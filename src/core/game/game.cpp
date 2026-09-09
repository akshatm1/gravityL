#include "game.h"

Game::Game() : player((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT){

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "GravityL" );
    

    ChangeDirectory(GetPrevDirectoryPath(GetWorkingDirectory()));
    SetTargetFPS( TARGET_FPS );
    DisableCursor();

/*
    OLD METHOD:
    arrowPointer = LoadTexture("assets/arrow.png");
    bulletTexture = LoadTexture("assets/orange_bullet_improved.png");
*/

    AssetManager::loadTexture2D( "arrowPointer", "assets/arrow.png" );
    AssetManager::loadTexture2D( "bulletTexture",  "assets/orange_bullet_improved.png" );

    world.genStar(MAX_STARS);
    world.genBuild(MAX_BUILDS, SCREEN_HEIGHT);
    world.genFlat();

}

Game::~Game(){

/*  
    OLD METHOD:
    UnloadTexture( arrowPointer );
    UnloadTexture( bulletTexture );
*/

    AssetManager::unloadALLTexture2D();

    CloseWindow();

}

void Game::draw(){

    ClearBackground(BLACK);

    BeginDrawing();

        BeginMode2D(mainCamera);
    
            world.draw();
            player.draw();
        
        EndMode2D();

        DrawText(TextFormat("velocity: %i", getPlayer().getVelocity().x), 50, 20, 25,YELLOW);

    EndDrawing();

}

void Game::update(){

    mainCamera.target = { player.getPosition().x, player.getPosition().y };
    mainCamera.offset = { (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2 };
    mainCamera.zoom = { 0.50f };
    player.update( SCREEN_WIDTH, SCREEN_HEIGHT );

}

void Game::run(){

    while (!WindowShouldClose()) {

        update();
        draw();

    }
}

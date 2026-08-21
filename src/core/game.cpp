#include "game.h"
#include <raylib.h>

Game::Game() : player((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT){
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "GravityL" );
    SetTargetFPS( TARGET_FPS );

    world.genStar(MAX_STARS);
    world.genBuild(MAX_BUILDS, SCREEN_HEIGHT);
    world.genFlat();

}

Game::~Game(){
    CloseWindow();
}

void Game::draw(){

    ClearBackground(BLACK);

    BeginDrawing();
        BeginMode2D(mainCamera);
            world.draw();
            player.draw();
        EndMode2D();
    EndDrawing();

}

void Game::update(){

    mainCamera.target = { player.getPosition().x, player.getPosition().y };
    mainCamera.offset = { (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2 };
    mainCamera.zoom = { 1.0f };
    player.update();

}

void Game::run(){
    while (!WindowShouldClose()) {
        update();
        draw();
    }
}
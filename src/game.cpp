#include "../include/game.h"
#include <raylib.h>

Game::Game(){
    InitWindow( SCREEN_WIDTH, SCREEN_HIGHT, "GravityL" );
    SetTargetFPS( TARGET_FPS );

    world.genStar(MAX_STARS);
    world.genBuild(MAX_BUILDS, SCREEN_HIGHT);
    world.genFlat();
}

Game::~Game(){
    CloseWindow();
}

void Game::draw(){

    ClearBackground(BLACK);
    
    BeginDrawing();
        world.draw();
    EndDrawing();

}

void Game::run(){
    while (!WindowShouldClose()) {
        draw();
    }
}
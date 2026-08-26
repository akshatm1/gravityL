#include "player.h"
#include <raylib.h>
#include <raymath.h>

Player::Player(const float &x, const float &y){
    position = { x/2, y/2 };
    velocity = { 0.0f, 0.0f };
    box.color = RED;

    accelFactor = { 7000000.0f, 30000.0f };
    friction = 15.0f;
    maxSpeed = 5000000000.0f;
}

void Player::update(){
    float dt = GetFrameTime();
    if(dt > 0.0016) dt = 0.0016;

    collisionDec = CheckCollisionRecs(box.dimen, {-6000, 430, 13000, 8000});

    inputDir.x = 0;
    inputDir.y = 0;

    if(IsKeyDown(KEY_RIGHT)) inputDir.x += 1.0f;
    if(IsKeyDown(KEY_LEFT)) inputDir.x -= 1.0f;
    if(IsKeyPressed(KEY_SPACE)) inputDir.y -= 1.0f;

    

    if (Vector2Length(inputDir)) {
    
        velocity.x = inputDir.x * accelFactor.x * dt;
        velocity.y = inputDir.y * accelFactor.y * dt;

    } else {
        
        velocity.x -= velocity.x * friction * dt;
        velocity.y += velocity.y * friction * dt;
        velocity.y += 100 * dt;
    }

    if ( Vector2Length(velocity) > maxSpeed ) {
        velocity = Vector2Scale(velocity, maxSpeed);
    }

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    box.dimen = { position.x, position.y, 70, 70};
}

void Player::draw(){
    DrawRectangleRec(box.dimen, box.color);
}
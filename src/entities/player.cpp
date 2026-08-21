#include "player.h"
#include <raylib.h>
#include <raymath.h>

Player::Player(const float &x, const float &y){
    position = { x/2, y/2 };
    velocity = { 0.0f, 0.0f };
    box.color = RED;

    accelFactor = { 2000.0f, 30.0f };
    friction = 10.0f;
    maxSpeed = 5000.0f;
}

void Player::update(){
    float dt = GetFrameTime();

    if(IsKeyDown(KEY_RIGHT)) inputDir.x += 1.0f;
    if(IsKeyDown(KEY_LEFT)) inputDir.x -= 1.0f;
    if(IsKeyDown(KEY_SPACE)) inputDir.y += 1.0f;

    if (Vector2Length(inputDir) > 0) {
        inputDir = Vector2Normalize(inputDir);
    }

    velocity.x = inputDir.x * accelFactor.x * dt;
    velocity.y = inputDir.y * accelFactor.y * dt;

    frictionFactor = 1/( 1 + friction * dt );
    velocity.x *= frictionFactor;
    velocity.y *= frictionFactor;

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
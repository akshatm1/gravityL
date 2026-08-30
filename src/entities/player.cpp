#include "player.h"
#include <raylib.h>
#include <raymath.h>

Player::Player(const float &x, const float &y){
    position = { x/2, y/2 };
    velocity = { 0.0f, 0.0f };
    box.color = RED;

    accelFactor = { 4000.0f, 600.0f };
    maxSpeed = 1000.0f;
    gravity = 1500.0f;
    jumpTimer = 0.0f;

    friction_gnd = 15.0f;
    friction_air = 4.0f;

    flatCD = { -6000, 430, 13000, 8000 };

}

void Player::update(){

// AI copy-pasted and some self-tweaked, I know I took help from an LLM but I just couldn't figure the physics out for so long:

float dt = GetFrameTime();
    if (dt > 0.05f) dt = 0.05f; 

    inputDir = { 0.0f, 0.0f };
    if (IsKeyDown(KEY_RIGHT)) inputDir.x += 1.0f;
    if (IsKeyDown(KEY_LEFT))  inputDir.x -= 1.0f;


    if ( IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) ){
        velocity.x += inputDir.x * accelFactor.x * dt;
    } 

    else {

        if( collisionDec == false ){
            velocity.x -= velocity.x * friction_air * dt;
        } 

        else {
            velocity.x -= velocity.x * friction_gnd * dt;
        }
    }

    if ( Vector2Length(velocity) > maxSpeed ) {
        velocity = Vector2Clamp(velocity, {-maxSpeed, -maxSpeed}, {maxSpeed, maxSpeed});
    }
    

    velocity.y += gravity * dt;


    if ( collisionDec && IsKeyPressed(KEY_SPACE) ) {
        velocity.y = -600.0f; 
    }
    else if ( !collisionDec && IsKeyPressed(KEY_SPACE) ){

        jumpTimer = 0.1f;
        jumpTimer -= GetFrameTime();
    
    }
    if( jumpTimer > 0 && collisionDec ){
        
        velocity.y = -600.0f;
        jumpTimer = 0.0f;

    }



    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    box.dimen = { position.x, position.y, 70, 70 };


    collisionDec = CheckCollisionRecs(box.dimen, flatCD);
    invisBoundL = CheckCollisionRecs(box.dimen, { ( flatCD.x - 1 ), 0, 1, 500 });
    invisBoundR = CheckCollisionRecs(box.dimen, { ( flatCD.x + flatCD.width + 1 ), 0, -1, 500 });

    if ( collisionDec ){

        position.y = flatCD.y - box.dimen.width; // Work for later, would change it to variables: DONE!
        velocity.y = 0;        
        box.dimen.y = position.y;
    
    }
    if ( invisBoundL ){

        position.x = flatCD.x;
        velocity.x = 0;
        box.dimen.x = position.x;

    }
    if ( invisBoundR ){

        position.x = ( flatCD.x + flatCD.width -  box.dimen.width );
        velocity.x = 0;
        box.dimen.x = position.x;

    }


}

void Player::draw(){

    DrawRectangleRec(box.dimen, box.color);

}
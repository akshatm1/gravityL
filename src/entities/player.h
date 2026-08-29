#pragma once
#include <raylib.h>

class Player{
private:
    Vector2 position;
    Vector2 velocity;

    Vector2 inputDir;
    Vector2 accelFactor;

    float maxSpeed;
    float gravity;
    bool collisionDec;
    
    float friction_air;
    float friction_gnd;


    struct play{
        Rectangle dimen;
        Color color;
    };
    play box;


public:
    Player(const float &x, const float &y);

    void update();
    void draw();

    Vector2 getPosition() const { return position; }
    Vector2 getVelocity() const { return velocity; }
};
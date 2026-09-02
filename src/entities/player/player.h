#pragma once
#include "player_arrow.h"
#include <raylib.h>

class Player{
private:

    ArrowGun gun;
    Vector2 position;
    Vector2 velocity;

    Vector2 inputDir;
    Vector2 accelFactor;

    float maxSpeed{};
    float gravity{};
    float jumpTimer{};

    bool collisionDec{};
    bool invisBoundL{};
    bool invisBoundR{};

    float friction_air{};
    float friction_gnd{};

    Rectangle flatCD;

    struct play{
        Rectangle dimen;
        Color color;
    };
    play box;


public:
    Player(const float &x, const float &y);

    void update( const float &x, const float &y );
    void draw( const Texture2D &ap );

    Vector2 getPosition() const { return position; }
    Vector2 getVelocity() const { return velocity; }
    Rectangle getPlayerDimen() const { return box.dimen; }

};
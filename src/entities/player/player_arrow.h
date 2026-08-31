#pragma once
#include <raylib.h>
#include <raymath.h>
#include <cmath>

class ArrowGun{
private:

    Vector2 mousePos;
    Vector2 centerPos;
    Vector2 arrowCoord;

    float dx{};
    float dy{};

    float arrowLength{};
    float angleInRad{};

public:
    ArrowGun( const float &x, const float &y );

    void update( const float &x, const float &y );
    void draw();

};
#pragma once
#include <raylib.h>
#include <raymath.h>
#include "../../core/bullet.h"
#include "../../core/assetManager.h"

class ArrowGun{
private:

    Bullet playerBullet;

    Vector2 mousePos;
    Vector2 mainCenterPos;
    Vector2 arrowCenterPos;

    Vector2 arrowCoord;
    Vector2 maxCursorBound;

    float dx{};
    float dy{};

    float arrowLength{};
    float angleInRad{};

public:
    ArrowGun();

    void update( const float& x, const float& y );
    void draw();

};
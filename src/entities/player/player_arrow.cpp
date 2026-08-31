#include "player_arrow.h"
#include <cmath>
#include <raylib.h>

ArrowGun::ArrowGun( const float &x, const float &y ){
    
    centerPos = { x/2 + 35, y/2 + 15 };

}

void ArrowGun::update( const float &x, const float &y ){

    mousePos = GetMousePosition();

    dx = mousePos.x - centerPos.x;
    dy = mousePos.y - centerPos.y;
    
    angleInRad = atan2(dy, dx);

    arrowLength = 150.0f;
    arrowCoord.x = arrowLength * cos( angleInRad ) + centerPos.x;
    arrowCoord.y = arrowLength * sin( angleInRad ) + centerPos.y;

}

void ArrowGun::draw(){

    DrawLineEx(centerPos, arrowCoord, 5.0f, WHITE);
}
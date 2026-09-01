#include "player_arrow.h"
#include <raylib.h>

ArrowGun::ArrowGun(){ 
    maxCursorBound = { 50, 50 };
}

void ArrowGun::update( const float &x, const float &y ){
    mainCenterPos = { x + 35, y + 35 };
    arrowLength = 150.0f;


    if ( GetMouseDelta().y > 0.1 ) {
        angleInRad += 0.1;
    }
    if ( GetMouseDelta().y < -0.1 ) {
        angleInRad -= 0.1;
    }

    arrowCenterPos = { ( 100 * cos(angleInRad) + mainCenterPos.x ), ( 100 * sin(angleInRad) + mainCenterPos.y ) };



    /*
    dx = mousePos.x - centerPos.x;
    dy = mousePos.y - centerPos.y;
    angleInRad = atan2(dy, dx);
    */
    arrowCoord.x = arrowLength * cos( angleInRad ) + arrowCenterPos.x ;
    arrowCoord.y = arrowLength * sin( angleInRad ) + arrowCenterPos.y ;
    

}

void ArrowGun::draw(){

    DrawLineEx(arrowCenterPos, arrowCoord, 5.0f, WHITE);
}
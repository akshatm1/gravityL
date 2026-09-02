#include "player_arrow.h"
#include <raylib.h>

ArrowGun::ArrowGun(){ 
    maxCursorBound = { 50, 50 };
}

void ArrowGun::update( const float &x, const float &y ){
    mainCenterPos = { x + 35, y + 35 };
    arrowLength = 150.0f;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) playerBullet.create(arrowCoord, 5000.0f, angleInRad );
    playerBullet.update( {x, y} );


    /*
    if ( GetMouseDelta().y > 0.1 ) {
        angleInRad += 0.1;
    }
    if ( GetMouseDelta().y < -0.1 ) {
        angleInRad -= 0.1;
    }
    */

    angleInRad += GetMouseDelta().x / 500;

    arrowCenterPos = { ( 60 * cos(angleInRad) + mainCenterPos.x ), ( 60 * sin(angleInRad) + mainCenterPos.y ) };



    /*
    dx = mousePos.x - centerPos.x;
    dy = mousePos.y - centerPos.y;
    angleInRad = atan2(dy, dx);
    */

    arrowCoord.x = arrowLength * cos( angleInRad ) + arrowCenterPos.x;
    arrowCoord.y = arrowLength * sin( angleInRad ) + arrowCenterPos.y;
    

}

void ArrowGun::draw( const Texture2D &ap ){

    //DrawLineEx(arrowCenterPos, arrowCoord, 5.0f, WHITE);
    playerBullet.draw();
    DrawTexturePro( ap, {0, 0, 155, 50}, { arrowCenterPos.x, arrowCenterPos.y, 190, 50 }, { 0, 25 }, ( angleInRad * 57.2958f), WHITE);
    
}
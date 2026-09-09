#include "player_arrow.h"
#include "src/core/assetManager/assetManager.h"

ArrowGun::ArrowGun(){ 
    maxCursorBound = { 50, 50 };
}

void ArrowGun::update( const float& x, const float& y ){

    mainCenterPos = { x + 35, y + 35 };
    arrowLength = 150.0f;

    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) playerBullet.create(arrowCoord, 2550.00f, angleInRad );
    playerBullet.update( {x, y} );


    angleInRad += GetMouseDelta().x / 500;
    arrowCenterPos = { ( 60 * cos(angleInRad) + mainCenterPos.x ), ( 60 * sin(angleInRad) + mainCenterPos.y ) };


    arrowCoord.x = arrowLength * cos( angleInRad ) + arrowCenterPos.x;
    arrowCoord.y = arrowLength * sin( angleInRad ) + arrowCenterPos.y;
    

}

void ArrowGun::draw(){

    //playerBullet.drawRec();
    playerBullet.drawTex( *( AssetManager::getTexture2D( "bulletTexture" ) ) );
    DrawTexturePro( *( AssetManager::getTexture2D( "arrowPointer" )), {0, 0, 155, 50}, { arrowCenterPos.x, arrowCenterPos.y, 190, 50 }, { 0, 25 }, ( angleInRad * 57.2958f ), WHITE);
    
}

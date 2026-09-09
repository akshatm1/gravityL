#include "bullet.h"



void Bullet::create( const Vector2& ogPos, const float& bulSpeed, const float& ang ){

    bullets.emplace_back( ogPos, bulSpeed, ang );

}

void Bullet::update( const Vector2& playerPos ){
    dt = GetFrameTime();

    
    for ( int i{}; i < bullets.size(); ) {

        bullets[i].pos.x += bullets[i].speed * cos(bullets[i].angle) * dt;
        bullets[i].pos.y += bullets[i].speed * sin(bullets[i].angle) * dt;

        if ( Vector2Distance( playerPos, bullets[i].pos) > 10000 ) {
            bullets[i] = bullets.back();
            bullets.pop_back();
        } 
        else i++;

    }

}


// FOR TESTING QUICKLY:
void Bullet::drawRec(){

    for ( int i{}; i < bullets.size(); i++ ) {

       DrawRectangle(bullets[i].pos.x, bullets[i].pos.y, 9, 13, Color( 247, 111, 21, 255 ));
    }
}

void Bullet::drawTex( const Texture2D& bulletT ){

    for ( int i{}; i < bullets.size(); i++ ){
        DrawTexturePro( bulletT, {0, 0, 150, 100}, {bullets[i].pos.x, bullets[i].pos.y, 15, 10}, {0, 7}, (bullets[i].angle * 57.2958f), WHITE);
    }

}

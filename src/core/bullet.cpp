#include "bullet.h"
#include <raymath.h>

/*
Bullet::Bullet( const Vector2& ogPos, const float& bulSpeed ){
    
    bullets.emplace_back( ogPos, bulSpeed, false );

}
*/

void Bullet::create( const Vector2 &ogPos, const float &bulSpeed, const float& ang ){

    bullets.emplace_back( ogPos, bulSpeed, ang, false );

}

void Bullet::update( const Vector2& playerPos ){
    dt = GetFrameTime();
    
    
    for ( int i{}; i < bullets.size(); i++ ) {
        
        bullets[i].pos = { (bullets[i].speed * cos(bullets[i].angle) * dt + bullets[i].pos.x), (bullets[i].speed * sin(bullets[i].angle) * dt + bullets[i].pos.y) };
        
        if ( Vector2Distance( playerPos, bullets[i].pos) > 10000 ) {
            std::swap(bullets[i], bullets.back());
            bullets.pop_back();
        }

    }

}

void Bullet::draw(){

    for ( int i{}; i < bullets.size(); i++ ) {
        DrawRectangle(bullets[i].pos.x, bullets[i].pos.y, 15, 15, RED);
    }

}
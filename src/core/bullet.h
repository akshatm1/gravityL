#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>

struct bullet{
    
    Vector2 pos;
    float speed{};
    float angle{};
};

class Bullet{
private:
    float dt;
    std::vector<bullet> bullets;

public:
    Bullet() = default;
    
    void create( const Vector2& ogPos, const float& bulSpeed, const float& ang );
    void update( const Vector2& playerPos );

    void drawRec();
    void drawTex( const Texture2D& bulletT );

};
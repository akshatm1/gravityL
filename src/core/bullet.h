#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <utility>

struct bullet{
    
    Vector2 pos;
    float speed;
    float angle;
    bool colDec{};

};

class Bullet{
private:
    float dt;
    std::vector<bullet> bullets;

public:
    //Bullet( const Vector2 &ogPos, const float &bulSpeed );
    Bullet() = default;
    void create( const Vector2 &ogPos, const float &bulSpeed, const float& ang );
    void update( const Vector2& playerPos );
    void draw();

};
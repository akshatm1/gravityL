#include "environment.h"
#include <raylib.h>

void Environment::genBuild( const int &maxBuilds, const int &screenHeight ){
    rectangleBuildings.resize(maxBuilds);

    for ( unsigned long i{}; i < rectangleBuildings.size(); i++) {
        rectangleBuildings[i].rect.width = { (float)GetRandomValue(50,100) };
        rectangleBuildings[i].rect.height = { (float)GetRandomValue(200, 650) };
        rectangleBuildings[i].rect.x = { -13000.0f + buildSpacing };
        rectangleBuildings[i].rect.y = { screenHeight - 100 - rectangleBuildings[i].rect.height };
        buildSpacing += rectangleBuildings[i].rect.width;

        rectangleBuildings[i].rectColor.r = { (unsigned char)GetRandomValue( 90,140 ) };
        rectangleBuildings[i].rectColor.g = { (unsigned char)GetRandomValue( 90,140 ) };
        rectangleBuildings[i].rectColor.b = { (unsigned char)GetRandomValue( 100,150 ) };
        rectangleBuildings[i].rectColor.a = { 255 };
    }
}

void Environment::genStar( const int &maxStars){
    stars.resize(maxStars);

    for(unsigned long i{}; i < stars.size(); i++){
        stars[i].dimen.height = { 3.0f };
        stars[i].dimen.width = { 3.0f };
        stars[i].dimen.x = { (float)GetRandomValue(-10000, 10000) };
        stars[i].dimen.y = { (float)GetRandomValue(-100, 2000)};
        stars[i].color = {255, 255, 255, 255};
    }
}

void Environment::genFlat(){
    flatform = { {-6000, 430, 13000, 8000}, GetColor(0x6a657dFF) };
}

void Environment::draw(){

    for ( unsigned long i{}; i < stars.size(); i++) {
        DrawRectangleRec( stars[i].dimen, stars[i].color );
    }

    for ( unsigned long i{}; i < rectangleBuildings.size(); i++) {
        DrawRectangleRec( rectangleBuildings[i].rect, rectangleBuildings[i].rectColor );
    }

    DrawRectangleRec(flatform.flat, flatform.flatColor);
}

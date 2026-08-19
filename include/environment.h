#pragma once
#include <raylib.h>
#include <vector>


struct building{
    Rectangle rect;
    Color rectColor;
};

struct star{
    Rectangle dimen;
    Color color;
};

struct platform{
    Rectangle flat;
    Color flatColor;
};

class Environment{
private:
    std::vector<building> rectangleBuildings;
    std::vector<star> stars;
    int buildSpacing{};
    platform flatform;

public:
    void genBuild( const int &maxBuilds, const int &screenHeight );
    void genStar( const int &maxStars );
    void genFlat();
    void draw();
};
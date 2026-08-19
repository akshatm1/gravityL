#pragma once
#include "../include/environment.h"

class Game{
private:
    static constexpr int SCREEN_WIDTH{ 1280 };
    static constexpr int SCREEN_HIGHT{ 720 };
    static constexpr int TARGET_FPS{ 60 };
    static constexpr int MAX_BUILDS{ 300 };
    static constexpr int MAX_STARS{ 3000 };

    Environment world;
    void draw();
public:
    Game();
    ~Game();

    void run();
};
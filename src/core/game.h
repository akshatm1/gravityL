#pragma once
#include "../world/environment.h"
#include "../entities/player/player.h"
#include "assetManager.h"
#include <raylib.h>

class Game{
private:
    static constexpr int SCREEN_WIDTH{ 1366 };
    static constexpr int SCREEN_HEIGHT{ 768 };
    static constexpr int TARGET_FPS{ 60 };
    static constexpr int MAX_BUILDS{ 180 };
    static constexpr int MAX_STARS{ 1000 };

    Player player;
    Environment world;

    Camera2D mainCamera = {  };
    
    void update();
    void draw();

    Texture2D arrowPointer;
    Texture2D bulletTexture;

public:
    Game();
    ~Game();

    void run();

    const Player& getPlayer() const { return player; }
};
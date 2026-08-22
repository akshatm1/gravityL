#pragma once
#include "../world/environment.h"
#include "../entities/player.h"

class Game{
private:
    static constexpr int SCREEN_WIDTH{ 1280 };
    static constexpr int SCREEN_HEIGHT{ 720 };
    static constexpr int TARGET_FPS{ 60 };
    static constexpr int MAX_BUILDS{ 300 };
    static constexpr int MAX_STARS{ 3000 };
    Player player;
    Environment world;
    Camera2D mainCamera = {  };
    void update();
    void draw();
public:
    Game();
    ~Game();

    void run();

    const Player& getPlayerREF() const { return player; }
};
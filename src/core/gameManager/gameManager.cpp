#include "gameManager.h"

GameManager::GameManager(){

   data = {
       {"player_accelFactor", {4000.0f, 600.0f} },
       {"player_maxSpeed", 2000.0f },
       {"player_gravity", 2000.0f},
       {"player_jmpFactor", -1100.0f},
       {"player_frctn_gnd", 15.0f},
       {"player_frctn_air", 4.0f},
       {"playerBullet_speed", 2550.0f},
    
   }; 

}

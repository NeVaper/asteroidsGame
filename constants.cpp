//---------------------------------------------------------------------------


#pragma hdrstop

#include "constants.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
        // resolution
        extern const int WIDTH = 920;
        extern const int HEIGHT = 640;
        extern const int WIDTH_BORDER = 10;
        extern const int HEIGHT_BORDER = 20;
        // spase ship
        extern const int INIT_POSITION_X = (WIDTH / 2);
        extern const int INIT_POSITION_Y = (HEIGHT / 2);
        extern const int INIT_POS_ACCELERATION = 1500;
        extern const int INIT_NEG_ACCELERATION = -100;
        extern const double MAX_SPEED = WIDTH;
        extern const int INIT_AMOUNT_OF_LIVES = 3;
        extern const int INVISIBLE_TIME = 2000;
        // bullets
        extern const double BULLET_INIT_SPEED = WIDTH;
        extern const int BULLET_LIFE_TIME = 1000;
        extern const int BULLET_RADIUS = 2;
        // asteroids
        extern const int ASTEROID_INIT_RADIUS = 50;
        extern const float ASTEROID_INIT_SPEED = 700;
        extern const int MAX_ROTATION_SPEED = 10; // ... * M_PI radian per second
        extern const int ASTEROID_MIN_RADIUS = 13;
        extern const int MINIMUM_SPAWN_GAP = 500;
        extern const int INIT_SPAWN_GAP = 7500;
        extern const float SCORE_MULTIPLIER = 0.3;

        // another
        extern const int DEFOULT_SCORE_MAAXIMUM = 2 * ASTEROID_INIT_RADIUS;


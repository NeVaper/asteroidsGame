//---------------------------------------------------------------------------

#ifndef constantsH
#define constantsH
//---------------------------------------------------------------------------
        // resolution
        extern const int WIDTH;
        extern const int HEIGHT;
        extern const int WIDTH_BORDER;
        extern const int HEIGHT_BORDER;
        // spase ship
        extern const int INIT_POSITION_X;
        extern const int INIT_POSITION_Y;
        extern const int INIT_POS_ACCELERATION;
        extern const int INIT_NEG_ACCELERATION;
        extern const double MAX_SPEED;
        extern const int INIT_AMOUNT_OF_LIVES;
        extern const int INVISIBLE_TIME;
        extern const int MINIMUM_SPAWN_GAP;
        extern const int INIT_SPAWN_GAP;
        extern const float SCORE_MULTIPLIER;
        // bullets
        extern const double BULLET_INIT_SPEED;
        extern const int BULLET_LIFE_TIME;
        extern const int BULLET_RADIUS;
        #define AMMOUNT_OF_BULLETS 3
        // asteroids
        extern const int ASTEROID_INIT_RADIUS;
        extern const float ASTEROID_INIT_SPEED;
        extern const int MAX_ROTATION_SPEED;
        extern const int ASTEROID_MIN_RADIUS;
        // another
        extern const int DEFOULT_SCORE_MAAXIMUM;
#endif

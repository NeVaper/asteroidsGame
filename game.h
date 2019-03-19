//---------------------------------------------------------------------------

#ifndef gameH
#define gameH
#include <time.h>
#include "spaceShip.h"
#include "asteroid.h"
#include "bullet.h"
//---------------------------------------------------------------------------

class Game {
    private:
        TImage* m_img;

        int m_lives;
        int m_timeWithoutSpwningNewAsteroid;
        int m_score;
        Asteroid* m_asteroids;
        clock_t m_time;
        clock_t m_timeDiff;

        void drawInfo();
        void addAsteroid();
        void processBullets();
    public:
        int m_shouldClose;
        SpaceShip* m_player;

        void terminateLoop() { m_shouldClose = 1; }
        int playGame();

        Game(TImage*);
        ~Game();
};

#endif

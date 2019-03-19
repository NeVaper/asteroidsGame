//---------------------------------------------------------------------------

#ifndef bulletH
#define bulletH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Windows.h>
#include "constants.h"
#include "asteroid.h"
//---------------------------------------------------------------------------

class Bullet {
    private:
        int m_lifeTime;
        float m_positionX;
        float m_positionY;
        float m_speedX;
        float m_speedY;
    public:
        int checkCollision(Asteroid *asteroids);
        int move(int timeDiff);
        Bullet(int initPosX, int initPosY,
               double vecX, double vecY,
               float initSpeedX = 0, float initSpeedY = 0);
        void draw(TImage *img);
};

#endif

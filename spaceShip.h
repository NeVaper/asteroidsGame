//---------------------------------------------------------------------------

#ifndef spaceShipH
#define spaceShipH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Windows.h>
#include <windows.h>
#include <mmsystem.h>
#include "bullet.h"


class SpaceShip {
     private:
        int *m_score;
        int m_invisibleTime;
        float  m_positionX;
        float  m_positionY;
        float  m_speedX;
        float  m_speedY;
        float  m_PosAcceleration;
        float  m_NegAcceleration;
        double m_vecX;
        double m_vecY;
        TPoint m_points[4];
        Bullet* m_bullets[AMMOUNT_OF_BULLETS];

        void calculateAngle();
        void accelerate(int timeDiff);
     public:
        int checkCollision(Asteroid *asteroids, int timeDiff);

        SpaceShip(int *score);
        void move(int timeDiff);
        void draw(TImage *img);
        void setDirection(int, int);
        void pew();
        Bullet** getBullets() { return m_bullets; }
};
//---------------------------------------------------------------------------
#endif

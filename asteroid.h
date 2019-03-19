//---------------------------------------------------------------------------

#ifndef asteroidH
#define asteroidH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Windows.h>
#include <windows.h>
#include <mmsystem.h>
#include <cmath>
//#define _USE_MATH_DEFINES

#include <constants.h>
//---------------------------------------------------------------------------
class Asteroid {
    private:
        float m_speedX;
        float m_speedY;
        double m_rotationSpeed;
        float m_rotationAngle;

        void setPattern(TPoint ver[10]);
    public:
        float m_positionX;
        float m_positionY;
        int m_radius;
        Asteroid *m_next;
        Asteroid *m_prev;
        Asteroid **m_start;

        void move(int timeDiff);
        void draw(TImage *img, int timeDiff);

        // for new random asteroids
        Asteroid(Asteroid **start, Asteroid *prev);
        // for new children
        Asteroid(int radius, float parent_speedX, float parent_speedY,
             float parent_positionX, float parent_positionY,
             double parent_rotationSpeed,
             Asteroid *next, Asteroid *prev, Asteroid **start);
        ~Asteroid();

};
#endif

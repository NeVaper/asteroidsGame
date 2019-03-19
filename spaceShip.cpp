//---------------------------------------------------------------------------


#pragma hdrstop
#include "sominGameForm.h"
#include <cmath>
#include "spaceShip.h"
#include "constants.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

SpaceShip::SpaceShip(int *score) {
        m_score = score;
        for (int i = 0; i < 10; ++i) {
                m_bullets[i] = NULL;
        }
        m_positionX = INIT_POSITION_X;
        m_positionY = INIT_POSITION_Y;
        m_vecX = 0;
        m_vecY = -1;
        m_speedX = 0;
        m_speedY = 0;
        m_PosAcceleration = INIT_POS_ACCELERATION;
        m_NegAcceleration = INIT_NEG_ACCELERATION;
        m_invisibleTime = 0;
}

void SpaceShip::draw(TImage *img) {
        calculateAngle();
        // cos(135) = cos(-135) = sin(-135) = -sin(135)
        static const double cos135 = -0.7071;
        // calculate position of points including rotate using pattern
        m_points[0] = TPoint((m_positionX + 12 * m_vecX), (m_positionY + 12 * m_vecY));
        m_points[1] = TPoint((m_positionX + 12 * ((m_vecX * cos135) - (m_vecY * -cos135))),
                        (m_positionY + 12 * ((m_vecX * -cos135) + (m_vecY * cos135 ))));
        m_points[2] = TPoint((m_positionX - 4 * m_vecX), (m_positionY - 4 * m_vecY));
        m_points[3] = TPoint((m_positionX + 12 * ((m_vecX * cos135) - (m_vecY * cos135))),
                        (m_positionY + 12 * ((m_vecX * cos135) + (m_vecY * cos135 ))));
        // draw
        img->Canvas->Brush->Color = clWhite;
        img->Canvas->Pen->Color = clWhite;
        if(m_invisibleTime > 0) {
                img->Canvas->Brush->Color = clNone;
        }
        img->Canvas->Polygon(m_points, 3);
}

void SpaceShip::calculateAngle() {    // find vector player-->mouse and normalize it
        TPoint mouse = mainForm->getMouse();
        mouse.x = mouse.x - m_positionX;
        mouse.y = mouse.y - m_positionY;
        if (!(mouse.x || mouse.y)) { return; }
        double powX = std::pow((double)mouse.x, 2);
        double powY = std::pow((double)mouse.y, 2);
        double c = std::sqrt(powX + powY);
        m_vecX = ((double)mouse.x) / c;
        m_vecY = ((double)mouse.y) / c;  
}

void SpaceShip::move(int timeDiff) {
        accelerate(timeDiff);
        m_positionX += m_speedX * timeDiff / 1000;
        m_positionY += m_speedY * timeDiff / 1000;
        // provide wrapping
        if (m_positionX < -1 * WIDTH_BORDER) {
                m_positionX = WIDTH + WIDTH_BORDER;
        } else if (m_positionX > WIDTH + WIDTH_BORDER) {
                m_positionX = -1 * WIDTH_BORDER;
        }
        if (m_positionY < -1 * HEIGHT_BORDER) {
                m_positionY = HEIGHT + HEIGHT_BORDER;
        } else if (m_positionY > HEIGHT + HEIGHT_BORDER) {
                m_positionY = -1 * HEIGHT_BORDER;
        }
}

void SpaceShip::accelerate(int timeDiff) {
        double hipotenuse = std::sqrt(m_speedX * m_speedX + m_speedY * m_speedY);
        if(GetKeyState(VK_SHIFT) & 0x8000) {  // Shift button down
                if (MAX_SPEED > hipotenuse) {
                        // calculate acceleration
                        m_speedX += timeDiff * m_PosAcceleration * m_vecX / 1000;
                        m_speedY += timeDiff * m_PosAcceleration * m_vecY / 1000;
                }
        } else {
                if (!(m_speedX || m_speedY)) { return; } // check division by zero
                // normalize movement vector
                double xMult, yMult;
                xMult = m_speedX / hipotenuse;
                yMult = m_speedY / hipotenuse;
                // calculate acceleration
                m_speedX += timeDiff * m_NegAcceleration * xMult / 1000;
                m_speedY += timeDiff * m_NegAcceleration * yMult / 1000;
        }
}

void SpaceShip::pew() {
        for(int i = 0; i < AMMOUNT_OF_BULLETS; ++i) {
                if (m_bullets[i] == NULL) {
                        m_bullets[i] = new Bullet(m_positionX, m_positionY, m_vecX, m_vecY, m_speedX, m_speedY);
                        PlaySound("sound\\fire.wav", NULL, SND_ASYNC);
                        return;
                }
        }
}

int SpaceShip::checkCollision(Asteroid *asteroids, int timeDiff) {
        if (m_invisibleTime <= 0) {
                for(int i = 0; i < 4; ++i) {
                        Asteroid *curAst = asteroids;
                        if(curAst != NULL) {
                                do {
                                        int dX = m_points[i].x - curAst->m_positionX;
                                        int dY = m_points[i].y - curAst->m_positionY;
                                        float dist = (dX * dX) + (dY * dY);
                                        dist = std::fabs(dist);
                                        dist = std::sqrt(dist);
                                        if(dist < curAst->m_radius) {
                                                m_invisibleTime = INVISIBLE_TIME;
                                                return 1;

                                        }
                                        curAst = curAst->m_next;
                                } while(curAst != NULL);
                        }
                }
        } else {
                m_invisibleTime -= timeDiff;
        }
        return 0;
}


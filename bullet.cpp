//---------------------------------------------------------------------------


#pragma hdrstop

#include "bullet.h"
#include "constants.h"
#include "game.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Bullet::Bullet(int initPosX, int initPosY,
        double vecX, double vecY,
        float  initSpeedX, float  initSpeedY) {
                m_lifeTime = 0;
                m_positionX = initPosX;
                m_positionY = initPosY;
                m_speedX = initSpeedX + BULLET_INIT_SPEED * vecX;
                m_speedY = initSpeedY + BULLET_INIT_SPEED * vecY;
}

int Bullet::move(int timeDiff) {
        m_positionX += timeDiff * m_speedX / 1000;
        m_positionY += timeDiff * m_speedY / 1000;
        // check lifetime
        m_lifeTime += timeDiff;
        if (m_lifeTime > BULLET_LIFE_TIME) {
        // set pointer to this object to NULL and free it`s memory
                return -1;
        }
        return 0;
}

void Bullet::draw(TImage *img) {
        img->Canvas->Brush->Color = clWhite;
        img->Canvas->Ellipse((m_positionX - BULLET_RADIUS), (m_positionY - BULLET_RADIUS),
                             (m_positionX + BULLET_RADIUS), (m_positionY + BULLET_RADIUS));
}

int Bullet::checkCollision(Asteroid *asteroids) {
        if (asteroids != NULL) {
                Asteroid *curAst = asteroids;
                do {
                        float dX = m_positionX - curAst->m_positionX;
                        float dY = m_positionY - curAst->m_positionY;
                        if(std::sqrt(dX * dX + dY * dY) < curAst->m_radius) {
                                int score = DEFOULT_SCORE_MAAXIMUM - curAst->m_radius;
                                delete curAst;
                                return score;
                        }
                        curAst = curAst->m_next;
                } while(curAst != NULL);
        }
        return 0;
}

//---------------------------------------------------------------------------


#pragma hdrstop

#include "asteroid.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

Asteroid::Asteroid(Asteroid **start, Asteroid *prev) {
        int sp = random(8);
        switch (sp) {
            case 0: // UP LEFT
                m_positionX = -1 * ASTEROID_INIT_RADIUS;
                m_positionY = -1 * ASTEROID_INIT_RADIUS;
                break;
            case 1: // MIDDLE LEFT
                m_positionX = -1 * ASTEROID_INIT_RADIUS;
                m_positionY = HEIGHT / 2.0;
                break;
            case 2: // DOWN LEFT
                m_positionX = -1 * ASTEROID_INIT_RADIUS;
                m_positionY = HEIGHT + ASTEROID_INIT_RADIUS;
                break;
            case 3: // DOWN MIDDLE
                m_positionX = WIDTH / 2.0;
                m_positionY = HEIGHT + ASTEROID_INIT_RADIUS;
                break;
            case 4: // DOWN RIGHT
                m_positionX = WIDTH + ASTEROID_INIT_RADIUS;
                m_positionY = HEIGHT + ASTEROID_INIT_RADIUS;
                break;
            case 5: // MIDDLE RIGHT
                m_positionX = WIDTH + ASTEROID_INIT_RADIUS;
                m_positionY = HEIGHT / 2.0;
                break;
            case 6: // UP RIGHT
                m_positionX = WIDTH + ASTEROID_INIT_RADIUS;
                m_positionY = -1 * ASTEROID_INIT_RADIUS;
                break;
            case 7: // UP MIDDLE
                m_positionX = WIDTH / 2.0;
                m_positionY = -1 * ASTEROID_INIT_RADIUS;
                break;
            default:
            m_positionX = 200;
            m_positionY = 200;
        }
        m_speedX = random((ASTEROID_INIT_SPEED + 1) * 2) - ASTEROID_INIT_SPEED;
        if (!m_speedX) { m_speedY = ASTEROID_INIT_SPEED;} // prevent zero division
        else {
                m_speedY = ASTEROID_INIT_SPEED * ASTEROID_INIT_SPEED - m_speedX * m_speedX;
                m_speedY = std::abs(m_speedY);
                m_speedY = std::sqrt(m_speedY);
                if ((random(100) - 50) < 0) {
                        m_speedY *= -1;
                }
        }
        m_rotationSpeed = M_PI * (random(MAX_ROTATION_SPEED * 2 + 1) - MAX_ROTATION_SPEED);
        m_rotationAngle = 0;
        m_radius = ASTEROID_INIT_RADIUS;
        m_prev = prev;
        m_next = NULL;
        m_start = start;
}

Asteroid::Asteroid(int radius, float parent_speedX, float parent_speedY,
    float parent_positionX, float parent_positionY,
    double parent_rotationSpeed,
    Asteroid *next, Asteroid *prev, Asteroid **start) {
        m_positionX = parent_positionX;
        m_positionY = parent_positionY;

        m_speedX = random((ASTEROID_INIT_SPEED + 1) * 2) - ASTEROID_INIT_SPEED;
        if (!m_speedX) { m_speedY = ASTEROID_INIT_SPEED;} // prevent zero division
        else {
                m_speedY = ASTEROID_INIT_SPEED * ASTEROID_INIT_SPEED - m_speedX * m_speedX;
                m_speedY = std::abs(m_speedY);
                m_speedY = std::sqrt(m_speedY);
                if ((random(100) - 50) < 0) {
                        m_speedY *= -1;
                }
        }
        m_speedX += parent_speedX;
        m_speedY += parent_speedY;

        m_rotationSpeed = M_PI * (random(MAX_ROTATION_SPEED * 2 + 1) - MAX_ROTATION_SPEED);
        m_rotationSpeed += parent_rotationSpeed;
        m_rotationAngle = 0;
        m_radius = radius;
        m_prev = prev;
        m_next = next;
        m_start = start;
    }

void Asteroid::draw(TImage *img, int timeDiff) {
        TPoint ver[10];
        setPattern(ver);
        img->Canvas->Pen->Color = clWhite;
        img->Canvas->Brush->Color = clNone;
        img->Canvas->Polygon(ver, 9);
}

void Asteroid::move(int timeDiff) {
        m_positionX += m_speedX / 1000;
        m_positionY += m_speedY / 1000;
        m_rotationAngle += m_rotationSpeed / 1000;
        if (m_positionX > WIDTH + m_radius){
                m_positionX = -1 * m_radius;
        } else if (m_positionX < (-1 * m_radius)) {
                m_positionX = WIDTH + m_radius;
        }
        if (m_positionY > HEIGHT + m_radius){
                m_positionY = -1 * m_radius;
        } else if (m_positionY < (-1 * m_radius)) {
                m_positionY = HEIGHT + m_radius;
        }
}

void Asteroid::setPattern(TPoint ver[10]) {
     ver[0].x = m_positionX - std::sin(m_rotationAngle) * m_radius * 0.95;
     ver[0].y = m_positionY - std::cos(m_rotationAngle) * m_radius * 0.95;
     ver[1].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 1) * m_radius * 0.90;
     ver[1].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 1) * m_radius * 0.90;
     ver[2].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 2) * m_radius * 1.05;
     ver[2].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 2) * m_radius * 1.05;
     ver[3].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 3) * m_radius * 0.93;
     ver[3].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 3) * m_radius * 0.93;
     ver[4].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 4) * m_radius * 1;
     ver[4].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 4) * m_radius * 1;
     ver[5].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 5) * m_radius * 1.02;
     ver[5].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 5) * m_radius * 1.02;
     ver[6].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 6) * m_radius * 1.0;
     ver[6].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 6) * m_radius * 1.0;
     ver[7].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 7) * m_radius * 0.9;
     ver[7].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 7) * m_radius * 0.9;
     ver[8].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 8) * m_radius * 1.05;
     ver[8].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 8) * m_radius * 1.05;
     ver[9].x = m_positionX - std::sin(m_rotationAngle + (M_PI / 5) * 9) * m_radius * 0.97;
     ver[9].y = m_positionY - std::cos(m_rotationAngle + (M_PI / 5) * 9) * m_radius * 0.97;
}

Asteroid::~Asteroid() {
        PlaySound("sound\\bang.wav", NULL, SND_ASYNC);
        if (m_radius <= ASTEROID_MIN_RADIUS) {
                // just delete it
                if (m_prev == NULL) {
                        if(m_next != NULL) {
                                *m_start = m_next;
                                m_next->m_prev = NULL;
                        } else {
                                *m_start = NULL;
                        }
                } else {
                        m_prev->m_next = m_next;
                        if (m_next != NULL) {
                                m_next->m_prev = m_prev;
                        }
                }
        } else {
                // born two new instead
                if (m_prev == NULL) {
                        Asteroid *secondAst = NULL;

                        secondAst = new Asteroid((m_radius / 2), m_speedX, m_speedY,
                        m_positionX, m_positionY, m_rotationSpeed,
                        m_next, NULL, m_start);

                        *m_start = new Asteroid((m_radius / 2), m_speedX, m_speedY,
                        m_positionX, m_positionY, m_rotationSpeed,
                        secondAst, NULL, m_start);

                        secondAst->m_prev = *m_start;

                        if (m_next != NULL) {
                                m_next->m_prev = secondAst;
                        }
                } else {
                        Asteroid *secondAst = NULL;

                        secondAst = new Asteroid((m_radius / 2), m_speedX, m_speedY,
                        m_positionX, m_positionY, m_rotationSpeed,
                        m_next, NULL, m_start);

                        m_prev->m_next = new Asteroid((m_radius / 2), m_speedX, m_speedY,
                        m_positionX, m_positionY, m_rotationSpeed,
                        secondAst, m_prev, m_start);

                        secondAst->m_prev = m_prev->m_next;

                        if (m_next != NULL) {
                                m_next->m_prev = secondAst;
                        }
                }
        }
}

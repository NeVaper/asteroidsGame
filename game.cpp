//---------------------------------------------------------------------------


#pragma hdrstop

#include "game.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

Game::Game(TImage *img) {
        m_lives = INIT_AMOUNT_OF_LIVES;
        m_score = 0;
        m_shouldClose = 0;
        m_time = clock();
        m_timeDiff = 0;
        m_timeWithoutSpwningNewAsteroid = 0;
        m_img = img;
        m_player = new SpaceShip(&m_score);
        m_asteroids = NULL;
        srand(time(NULL));
        for (int i = 0; i < 2; ++i) {
                addAsteroid();
        }
}

Game::~Game() {}

Game::playGame() {
        while(!(m_shouldClose) && (m_lives > 0)) {
        // prepare new frame
                m_img->Canvas->Brush->Color = clBlack;
                m_img->Canvas->FillRect(TRect(0,0,WIDTH,HEIGHT));
        // calculate last frame time
                m_timeDiff = clock() - m_time;
                m_time = clock();
        // process asteriods
                Asteroid *asteroid = m_asteroids;
                while(asteroid != NULL) {
                        asteroid->move(m_timeDiff);
                        asteroid->draw(m_img, m_timeDiff);
                        asteroid = asteroid->m_next;
                }
        // process player
        m_player->move(m_timeDiff);
        m_player->draw(m_img);
        if(m_player->checkCollision(m_asteroids, m_timeDiff)) {
                m_lives--;
                if(m_lives) {
                        PlaySound("sound\\ship.wav", NULL, SND_ASYNC);
                } else {
                        PlaySound("sound\\largeBang.wav", NULL, SND_ASYNC);
                }
        }

        processBullets();

        // spawn new asteroid (if it is time)
        if(m_timeWithoutSpwningNewAsteroid > MINIMUM_SPAWN_GAP) {
                if(m_timeWithoutSpwningNewAsteroid > (INIT_SPAWN_GAP - (m_score * SCORE_MULTIPLIER))) {
                        addAsteroid();
                        m_timeWithoutSpwningNewAsteroid = 0;
                }
        }
        drawInfo();
        // ending
        m_timeWithoutSpwningNewAsteroid += m_timeDiff;
        Application->ProcessMessages();
        }
        return m_score;
}

void Game::addAsteroid() {
        Asteroid *lastAsteroid = m_asteroids;
        if (lastAsteroid != NULL) {
                while(lastAsteroid->m_next != NULL) {
                        lastAsteroid = lastAsteroid->m_next;
                }
                srand((int)lastAsteroid);
                lastAsteroid->m_next = new Asteroid(&m_asteroids, lastAsteroid);
        } else {
                m_asteroids = new Asteroid(&m_asteroids, NULL);
        }
}

void Game::processBullets() {
        Bullet **bullets = m_player->getBullets();
        for (int i = 0; i < AMMOUNT_OF_BULLETS; ++i) {
                if (bullets[i] != NULL) {
                        if(bullets[i]->move(m_timeDiff)) {
                                bullets[i] = NULL;
                                continue;
                        }
                        int score = bullets[i]->checkCollision(m_asteroids);
                        if(score) {
                                free(bullets[i]);
                                bullets[i] = NULL;
                                if(score > 0) {
                                        m_score += score;
                                }
                                continue;
                        }
                        bullets[i]->draw(m_img);
                }
        }
}

void Game::drawInfo() {
        m_img->Canvas->Font->Size = 20;
        m_img->Canvas->Font->Color = clWhite;
        m_img->Canvas->Brush->Color = clNone;
        m_img->Canvas->Pen->Color = clWhite;
        AnsiString inf;
        inf = "Score: ";
        inf += m_score;
        inf += "  Lives: ";
        inf += m_lives;
        m_img->Canvas->TextOutA(5,5, inf);
}

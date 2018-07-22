#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <map>
#include <vector>

#include "TexturesAndRects.h"
#include "TimerMgr.h"

enum EHeroStates
{
    heroAfterAction,
    heroStaying,
    heroJumping,
    heroWalking,
    heroBeating,
    heroDie,
    heroGameOver
};

enum EEnemyStates
{
    enemyInactive,
    enemyComing,
    enemyAttacking,
    enemyDie,
    enemyUncoming
};

class GameLoop
{
private:

    SDL_Window* window = nullptr;


public:

    GameLoop();

    unsigned short m_HeroStates;

    unsigned short m_EnemyStates;
    
    bool m_bBlink = true;

    int m_HealthCounter = 109;

    TexturesAndRects m_Textures;

    //Initialize all SDL Components
    bool InitSdl();

    // Main Game Loop
    void MainLoop();

    /* Drawing */
    void Draw( SDL_Texture* TextureToDraw, SDL_Rect* RectFromTexture, SDL_Rect* RectToDrawOnScreen );

    void PresentScreen();
    /*                  */

    // Button Events
    bool ButtonPressed(SDL_Event* eventsHandler);



};

extern GameLoop gGameLoop;

#endif // GAMELOOP_H

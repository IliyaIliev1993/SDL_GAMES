#ifndef TEXTURESANDRECTS_H
#define TEXTURESANDRECTS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <vector>

class TexturesAndRects
{
public:

    TexturesAndRects();

    SDL_Renderer* renderer = nullptr;

    SDL_Texture* texture_background = nullptr;

    SDL_Texture* texture_ground = nullptr;

    SDL_Texture* texture_palma = nullptr;
    
    SDL_Texture* texture_gameOver = nullptr;

    SDL_Texture* LoadTextureFromPath(std::string pathToTexture);

    void LoadingAllTextures();


    //Vectors with animations
    std::vector<SDL_Texture*>m_vecHealthIndicator;

    std::vector<SDL_Texture*>m_vecHeroStaying;

    std::vector<SDL_Texture*>m_vecHeroJumping;

    std::vector<SDL_Texture*>m_vecHeroWalking;

    std::vector<SDL_Texture*>m_vecHeroBeating;

    std::vector<SDL_Texture*>m_vecHeroDie;

    //Vector with animations of enemy
    std::vector<SDL_Texture*>m_vecEnemyWalking;

    std::vector<SDL_Texture*>m_vecEnemyBeat;
    
    std::vector<SDL_Texture*>m_vecEnemyDie;

    // RECTS
    SDL_Rect rectWallpaper = {0,0,1440,780};
    
    SDL_Rect rectBackground = {0,0,1440,780};
    
    SDL_Rect rectBackgroundLoop = {1440,0,1440,780};

    SDL_Rect rectGround = {0,0,1440,780};
    
    SDL_Rect rectGroundLoop = {1440,0,1440,780};

    SDL_Rect rectHealthIndicator = {20,0,300,100};
    
    SDL_Rect rectGameOver = {0, 880, 1440, 780};

    //Normal Y = 420, when coming is initialized to -350 to hide
    SDL_Rect rectHero = {10,-350, 450, 300};

    SDL_Rect rectHeroJumping = {0, 250, 600, 500};

    SDL_Rect rectHeroWalking = {10, 430, 500, 300};

    SDL_Rect rectHeroAttack = {-100, 200, 650, 550};

    SDL_Rect rectHeroDie = {10, 450, 500, 370};

    SDL_Rect rectEnemyComing = {1440, 520, 190, 210};

    SDL_Rect rectEnemyAttack = {1440, 520, 400, 200};
    
    SDL_Rect rectEnemyDie = {1440, 560, 210, 200};
};

#endif // TEXTURESANDRECTS_H

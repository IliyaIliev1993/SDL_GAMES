#include "GameLoop.h"
#include <exception>

const int n_window_width = 1440;
const int n_window_height = 780;


bool b_gameCycle = true;

SDL_Event eventsHandler;


GameLoop::GameLoop()
{


}


//Initialize All SDL Components
bool GameLoop::InitSdl()
{
    if((SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        std::cout << "ERROR: Initialzie Audio,Video or Timer" << std::endl;
        
        return false;
    }
    else
    {
        window = SDL_CreateWindow("GameProject", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, n_window_width, n_window_height, SDL_WINDOW_SHOWN);

        if(window == NULL)
        {
            std::cout << "ERROR: Creating Window" << std::endl;
            
            return false;
        }
        else
        {
            m_Textures.renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_OPENGL);

            if(m_Textures.renderer == NULL)
            {
                std::cout << "ERROR: Creating Renderer" << std::endl;
                
                return false;
            }
        }
    }
    
    return true;
}


//Draw Function
void GameLoop::Draw(SDL_Texture* TextureToDraw, SDL_Rect* RectFromTexture, SDL_Rect* RectToDrawOnScreen )
{
    SDL_RenderCopy(m_Textures.renderer, TextureToDraw, RectFromTexture, RectToDrawOnScreen);
}

//Presen and update the screen
void GameLoop::PresentScreen()
{
    SDL_RenderPresent(m_Textures.renderer);
}

//Event Handler for Buttons (returns true if pressed)
bool GameLoop::ButtonPressed(SDL_Event* eventsHandler)
{
    if( gGameLoop.m_HeroStates == heroDie || gGameLoop.m_HeroStates == heroGameOver )
    {
        gTimer.StopTimer(gTimer.timerHeroeStaying);
        
        gTimer.StopTimer(gTimer.timerHeroeWalking);
        
        gTimer.StopTimer(gTimer.timerHeroeWalkingBack);
        
        gTimer.StopTimer(gTimer.timerHeroeJumping);
        
        gTimer.StopTimer(gTimer.timerHeroeAttacking);
        
        return false;
    }
    if(eventsHandler->key.keysym.sym == SDLK_d && eventsHandler->type == SDL_KEYDOWN)
    {
        gGameLoop.m_HeroStates = heroWalking;

        gTimer.StopTimer(gTimer.timerHeroeStaying);

        gTimer.StartTimer(gTimer.timerHeroeWalking);

        return true;

    }
    else if(eventsHandler->key.keysym.sym == SDLK_d &&
             eventsHandler->type == SDL_KEYUP)
    {

        gTimer.StopTimer(gTimer.timerHeroeWalking);

        gGameLoop.m_HeroStates = heroAfterAction;
    }

    //Walking Back
    if(eventsHandler->key.keysym.sym == SDLK_a && eventsHandler->type == SDL_KEYDOWN)
    {
        gGameLoop.m_HeroStates = heroWalking;

        gTimer.StopTimer(gTimer.timerHeroeStaying);

        gTimer.StartTimer(gTimer.timerHeroeWalkingBack);

        return true;

    }
    else if(eventsHandler->key.keysym.sym == SDLK_a &&
             eventsHandler->type == SDL_KEYUP)
    {

        gTimer.StopTimer(gTimer.timerHeroeWalkingBack);

        gGameLoop.m_HeroStates = heroAfterAction;
    }

    //Jumping
    if(eventsHandler->key.keysym.sym == SDLK_w)
    {
        gGameLoop.m_HeroStates = heroJumping;

        gTimer.StopTimer(gTimer.timerHeroeStaying);

        gTimer.StartTimer(gTimer.timerHeroeJumping);

        return true;

    }

    //Beating
    if(eventsHandler->key.keysym.sym == SDLK_SPACE)
    {
        gGameLoop.m_HeroStates = heroBeating;

        gTimer.StopTimer(gTimer.timerHeroeStaying);

        gTimer.StartTimer(gTimer.timerHeroeAttacking);

    }

    return false;
}

//Main Loop needed for the game
void GameLoop::MainLoop()
{
    InitSdl();

    m_Textures.LoadingAllTextures();
    
    gTimer.StartTimer(gTimer.timerHeroeComing);
    
    gTimer.StartTimer(gTimer.timerEnemyesAppear);

    while( b_gameCycle )
    {


        while(SDL_PollEvent(&eventsHandler) /*!= 0*/)
        {
            if( eventsHandler.type == SDL_QUIT ||
                eventsHandler.key.keysym.sym == SDLK_ESCAPE )
            {
                b_gameCycle = false;
            }

            ButtonPressed(&eventsHandler);

        }

        Draw(m_Textures.texture_background, NULL, &gGameLoop.m_Textures.rectWallpaper);

        Draw(m_Textures.texture_palma, NULL, &gGameLoop.m_Textures.rectBackground);
        
        Draw(m_Textures.texture_palma, NULL, &gGameLoop.m_Textures.rectBackgroundLoop);

        Draw(m_Textures.texture_ground, NULL, &gGameLoop.m_Textures.rectGround);
        
        Draw(m_Textures.texture_ground, NULL, &gGameLoop.m_Textures.rectGroundLoop);
        
        if( gGameLoop.m_bBlink )
        {
            Draw(m_Textures.m_vecHealthIndicator[gGameLoop.m_HealthCounter / 10], NULL, &m_Textures.rectHealthIndicator);
        }

        switch(gGameLoop.m_EnemyStates)
        {
        case enemyComing:

                Draw(m_Textures.m_vecEnemyWalking[gTimer.animEnemyComing], NULL, &gGameLoop.m_Textures.rectEnemyComing);

            break;
         
        case enemyAttacking:

                Draw(m_Textures.m_vecEnemyBeat[gTimer.animEnemyAttack], NULL, &gGameLoop.m_Textures.rectEnemyAttack);

            break;
                
        case enemyDie:
            
            Draw(m_Textures.m_vecEnemyDie[gTimer.animEnemyDie], NULL, &gGameLoop.m_Textures.rectEnemyDie);
            
            break;
                
        case enemyUncoming:
            
            Draw(m_Textures.m_vecEnemyDie[gTimer.animEnemyDie], NULL, &gGameLoop.m_Textures.rectEnemyDie);
            
            break;
                

        default:

            break;
        }


        switch( gGameLoop.m_HeroStates )
        {
        case heroAfterAction:

            gGameLoop.m_HeroStates = heroStaying;

            gTimer.StartTimer(gTimer.timerHeroeStaying);

            break;

        case heroStaying:

            Draw(m_Textures.m_vecHeroStaying[gTimer.animStaying], NULL, &gGameLoop.m_Textures.rectHero);

            break;

        case heroJumping:

            Draw(m_Textures.m_vecHeroJumping[gTimer.animJumping], NULL, &gGameLoop.m_Textures.rectHeroJumping);

            break;

        case heroWalking:

            Draw(m_Textures.m_vecHeroWalking[gTimer.animWalking], NULL, &gGameLoop.m_Textures.rectHeroWalking);

            break;

        case heroBeating:

            Draw(m_Textures.m_vecHeroBeating[gTimer.animHeroeAttack], NULL, &gGameLoop.m_Textures.rectHeroAttack);

            break;

        case heroDie:

            Draw(m_Textures.m_vecHeroDie[gTimer.animHeroeDie], NULL, &gGameLoop.m_Textures.rectHeroDie);

            break;
                
        case heroGameOver:
                
            Draw(m_Textures.m_vecHeroDie[gTimer.animHeroeDie], NULL, &gGameLoop.m_Textures.rectHeroDie);
            
            Draw(m_Textures.texture_gameOver, NULL, &gGameLoop.m_Textures.rectGameOver);
            
            break;


        default:

            break;
        }



        PresentScreen();

    }

}



GameLoop gGameLoop;

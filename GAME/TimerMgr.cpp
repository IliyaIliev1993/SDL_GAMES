#include "TimerMgr.h"
#include "GameLoop.h"


TimerMgr::TimerMgr()
{

}

Uint32 TickTime( Uint32 interval, void* param )
{
    
    int n_xHero = 10;
    
    int n_yHero = 5;
    
    const int n_ponintOfLoop = 300;
    
    if( interval == gTimer.timerHeroeComing )
    {
        gGameLoop.m_Textures.rectHero.y += n_yHero;
        
        if(gGameLoop.m_Textures.rectHero.y >= 420)
        {
            gGameLoop.m_Textures.rectHero.y = 420;
            
            gTimer.StopTimer(gTimer.timerHeroeComing);
        }
    }
    
    if( interval == gTimer.timerEnemyesAppear )
    {
        if(gGameLoop.m_HealthCounter <= 50)
        {
            gGameLoop.m_bBlink = !gGameLoop.m_bBlink;
        }
        const int nSecondsToComeEnemy = 5;
        
        gTimer.un_enemyAppear += 1;
        
        if( gTimer.un_enemyAppear % nSecondsToComeEnemy == 0 && gGameLoop.m_EnemyStates == enemyInactive )
        {
            gGameLoop.m_Textures.rectEnemyComing = {1440, 520, 190, 210};
            
            gGameLoop.m_Textures.rectEnemyAttack = {1440, 520, 400, 200};
            
            gGameLoop.m_Textures.rectEnemyDie = {1440, 560, 210, 200};
            
            gTimer.StartTimer(gTimer.timerEnemyComing);
            
            gGameLoop.m_EnemyStates = enemyComing;
        }
    }

    if(interval == gTimer.timerHeroeStaying)
    {

       gTimer.animStaying++;

        if(gTimer.animStaying > 9)
        {
           gTimer.animStaying = 0;
        }

    }

    if(interval == gTimer.timerHeroeJumping)
    {
        int xHero = 5;
        
        gTimer.animJumping++;

        gGameLoop.m_Textures.rectHeroWalking.x += xHero;

        gGameLoop.m_Textures.rectHeroJumping.x += xHero;

        gGameLoop.m_Textures.rectHeroAttack.x += xHero;

        gGameLoop.m_Textures.rectHero.x += xHero;


         if(gTimer.animJumping > 9)
         {
            gTimer.animJumping = 0;

            gTimer.StopTimer(gTimer.timerHeroeJumping);

            gGameLoop.m_HeroStates = heroAfterAction;

         }

    }

    if(interval == gTimer.timerHeroeWalking)
    {
        gTimer.animWalking++;

        //Loop Effect
        if( gGameLoop.m_Textures.rectHero.x >= n_ponintOfLoop )
        {
            gGameLoop.m_Textures.rectGround.x -= n_xHero / 2;
            
            gGameLoop.m_Textures.rectGroundLoop.x -= n_xHero / 2;
            
            gGameLoop.m_Textures.rectBackground.x -= n_xHero / 10;
            
            gGameLoop.m_Textures.rectBackgroundLoop.x -= n_xHero / 10;
            
            if( (gGameLoop.m_Textures.rectGround.x + gGameLoop.m_Textures.rectGround.w) <= 0 )
            {
                gGameLoop.m_Textures.rectGround.x = gGameLoop.m_Textures.rectGround.w;
            }
            
            if( (gGameLoop.m_Textures.rectGroundLoop.x + gGameLoop.m_Textures.rectGroundLoop.w) <= 0 )
            {
                gGameLoop.m_Textures.rectGroundLoop.x = gGameLoop.m_Textures.rectGroundLoop.w;
            }
            
            if( (gGameLoop.m_Textures.rectBackground.x + gGameLoop.m_Textures.rectBackground.w) <= 0 )
            {
                gGameLoop.m_Textures.rectBackground.x = gGameLoop.m_Textures.rectBackground.w;
            }
            
            if( (gGameLoop.m_Textures.rectBackgroundLoop.x + gGameLoop.m_Textures.rectBackgroundLoop.w) <= 0 )
            {
                gGameLoop.m_Textures.rectBackgroundLoop.x = gGameLoop.m_Textures.rectBackgroundLoop.w;
            }
        }
        else
        {
            gGameLoop.m_Textures.rectHeroWalking.x += n_xHero;
            
            gGameLoop.m_Textures.rectHeroJumping.x += n_xHero;
            
            gGameLoop.m_Textures.rectHeroAttack.x += n_xHero;
            
            gGameLoop.m_Textures.rectHero.x += n_xHero;
            
            gGameLoop.m_Textures.rectHeroDie.x += n_xHero;
        }

        if(gTimer.animWalking > 9)
        {
            gTimer.animWalking = 0;
        }

    }

    if(interval == gTimer.timerHeroeWalkingBack)
    {
        gTimer.animWalking--;

        gGameLoop.m_Textures.rectHeroWalking.x -= n_xHero;

        gGameLoop.m_Textures.rectHeroJumping.x -= n_xHero;

        gGameLoop.m_Textures.rectHeroAttack.x -= n_xHero;

        gGameLoop.m_Textures.rectHero.x -= n_xHero;
        
        gGameLoop.m_Textures.rectHeroDie.x -= n_xHero;

        if(gTimer.animWalking <= 0)
        {
            gTimer.animWalking = 9;
        }
    }

    if(interval == gTimer.timerHeroeAttacking)
    {
        gTimer.animHeroeAttack++;

        if(gTimer.animHeroeAttack > 9)
        {
            gTimer.animHeroeAttack = 0;

            gTimer.StopTimer(gTimer.timerHeroeAttacking);

            gGameLoop.m_HeroStates = heroAfterAction;

        }

    }

    if(interval == gTimer.timerEnemyComing)
    {
        short xOffset = 230;
        
        gTimer.animEnemyComing += 1;
        
        if( gTimer.animEnemyComing >= 5 )
        {
            gTimer.animEnemyComing = 0;
        }
        
        gGameLoop.m_Textures.rectEnemyComing.x -= 20;
        
        gGameLoop.m_Textures.rectEnemyAttack.x -= 20;
        
        gGameLoop.m_Textures.rectEnemyDie.x -= 20;
        
        if( ( gGameLoop.m_Textures.rectEnemyComing.x ) <= ( gGameLoop.m_Textures.rectHero.x + gGameLoop.m_Textures.rectHero.w ) )
        {
            gGameLoop.m_Textures.rectEnemyAttack.x -= xOffset;
            
            gTimer.StartTimer(gTimer.timerEnemyAttack);
            
            gGameLoop.m_EnemyStates = enemyAttacking;
            
            gTimer.StopTimer(gTimer.timerEnemyComing);
        }
        
        
    }

    if(interval == gTimer.timerEnemyAttack)
    {
        gTimer.animEnemyAttack++;

        if(gTimer.animEnemyAttack >= 5)
        {
            gTimer.animEnemyAttack = 0;
            
            gGameLoop.m_HealthCounter -= 5;

        }
        //Hero Die
        if( gGameLoop.m_HealthCounter <= 0)
        {
            gGameLoop.m_HealthCounter = 0;
            
            gGameLoop.m_HeroStates = heroDie;
            
            gTimer.StartTimer(gTimer.timerHeroeDie);
            
            gTimer.StopTimer(gTimer.timerEnemyAttack);
            
        }
        
        //Enemy Die just if heroe is in 8 frame
        if( gGameLoop.m_HeroStates == heroBeating && gTimer.animHeroeAttack == 8 )
        {
            gGameLoop.m_EnemyStates = enemyDie;
            
            gTimer.StartTimer(gTimer.timerEnemyDie);
            
            gTimer.StopTimer(gTimer.timerEnemyAttack);
        }
    }
    
    if( interval == gTimer.timerEnemyDie )
    {
        gTimer.animEnemyDie++;
        
        if( gTimer.animEnemyDie > 4 )
        {
            gTimer.animEnemyDie = 4;
        }
        
        if( ( ( gGameLoop.m_Textures.rectHero.x + gGameLoop.m_Textures.rectHero.w ) >= gGameLoop.m_Textures.rectEnemyDie.x ) &&
            gGameLoop.m_HeroStates == heroWalking )
        {
            gTimer.StopTimer(gTimer.timerEnemyDie);
            
            gGameLoop.m_EnemyStates = enemyUncoming;
            
            gTimer.StartTimer(gTimer.timerEnemyUncoming);
        }
    }
    
    if( interval == gTimer.timerEnemyUncoming )
    {
        gGameLoop.m_Textures.rectEnemyDie.y -= 20;
        
        if( gGameLoop.m_Textures.rectEnemyDie.y <= -gGameLoop.m_Textures.rectEnemyDie.h )
        {
            gTimer.StopTimer( gTimer.timerEnemyUncoming );
            
            gGameLoop.m_EnemyStates = enemyInactive;
        }
    }

    if(interval == gTimer.timerHeroeDie)
    {
        gTimer.animHeroeDie++;

        if(gTimer.animHeroeDie > 9)
        {
            gTimer.animHeroeDie = 9;

            gTimer.StopTimer(gTimer.timerHeroeDie);
            
            gTimer.StartTimer(gTimer.timerGameOver);
            
            gGameLoop.m_HeroStates = heroGameOver;
        }

    }
    
    if( interval == gTimer.timerGameOver )
    {
        gGameLoop.m_Textures.rectGameOver.y -= 5;
        
        if( gGameLoop.m_Textures.rectGameOver.y <= 0 )
        {
            gGameLoop.m_Textures.rectGameOver.y = 0;
            
            gTimer.StopTimer(gTimer.timerGameOver);
        }
    }

    return interval;
}

void TimerMgr::StartTimer( int periodAndId )
{

    SDL_TimerID timerToAdd = SDL_AddTimer(periodAndId, TickTime, NULL);

    if( mapOfTimers.find(periodAndId) == mapOfTimers.end() )
    {
        mapOfTimers[periodAndId] = timerToAdd;

        std::cout << "Timer added -> " << periodAndId << std::endl;

    }
    else
    {
        SDL_RemoveTimer(timerToAdd);

        std::cout << "ERROR: Timer with ID -> " << periodAndId << " already exist ..." << std::endl;
    }

}

void TimerMgr::StopTimer( int periodAndId )
{
    if( mapOfTimers.find(periodAndId) != mapOfTimers.end() )
    {
        SDL_RemoveTimer( mapOfTimers.at(periodAndId) );

        mapOfTimers.erase( periodAndId );

        std::cout << "Timer -> " << periodAndId << " was deleted..." << std::endl;
    }
    else
    {
        //std::cout << "Timer -> " << periodAndId << " was not found..." << std::endl;
    }
}



TimerMgr gTimer;

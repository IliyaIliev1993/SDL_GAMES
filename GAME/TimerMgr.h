#ifndef TIMERMGR_H
#define TIMERMGR_H

#include <iostream>
#include <SDL2/SDL.h>
#include <map>


class TimerMgr
{

private:

    std::map<int,SDL_TimerID>mapOfTimers;

public:

    TimerMgr();

    void StartTimer( int periodAndId );

    void StopTimer( int periodAndId );

    //Timers and Animation sequence
    int timerHeroeStaying = 40;
    unsigned short animStaying = 0;

    int timerHeroeJumping = 60;
    unsigned short animJumping = 0;

    int timerHeroeWalking = 55;
    unsigned short animWalking = 0;

    int timerHeroeWalkingBack = 56;

    int timerEnemyAttack = 100;
    unsigned short animEnemyAttack = 0;

    int timerEnemyComing = 57;
    unsigned short animEnemyComing = 0;
    
    int timerEnemyDie = 58;
    unsigned short animEnemyDie = 0;
    
    int timerEnemyUncoming = 11;

    int timerHeroeAttacking = 52;
    unsigned short animHeroeAttack = 0;

    int timerHeroeDie = 53;
    unsigned short animHeroeDie = 0;
    
    int timerGameOver = 30;
    
    int timerHeroeComing = 10;
    
    int timerEnemyesAppear = 1000;
    unsigned int un_enemyAppear = 0;

};

Uint32 TickTime( Uint32 interval, void* param);

extern TimerMgr gTimer;

#endif // TIMERMGR_H

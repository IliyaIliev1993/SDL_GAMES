#include "TexturesAndRects.h"
#include "GameLoop.h"

TexturesAndRects::TexturesAndRects()
{

}


//Loading Texture from Path (string)
SDL_Texture* TexturesAndRects::LoadTextureFromPath(std::string pathToTexture)
{
    SDL_Texture* texture_to_return = nullptr;

    texture_to_return = IMG_LoadTexture(renderer, pathToTexture.c_str());

    std::cout << "Loading -> " << pathToTexture << std::endl;

    if(texture_to_return == NULL)
    {
        std::cout << "ERROR: Problem to load texture: " << pathToTexture << std::endl;
    }

    return texture_to_return;
}


//Loading all textures needed for the game
void TexturesAndRects::LoadingAllTextures()
{
    texture_background = LoadTextureFromPath("nebe.png");

    texture_ground = LoadTextureFromPath("zemq.png");

    texture_palma = LoadTextureFromPath("palmi.png");
    
    texture_gameOver = LoadTextureFromPath("gameOver.png");

    //Loading Health Indicator
    for(int i = 0; i <= 10; i++)
    {
        std::string strAnim = "HealthIndicator/health_bar_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHealthIndicator.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    // Loading Staying Animation
    for(int i = 0; i < 10; i++)
    {

        std::string strAnim = "AnimTroll1Staiyng/Idle_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHeroStaying.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    // Loading Jumping Animation
    for(int i = 0; i < 10; i++)
    {
        std::string strAnim = "AnimTroll1Jumping/Jump_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHeroJumping.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    //Loading Walking Animation
    for(int i = 0; i < 10; i++)
    {
        std::string strAnim = "AnimTroll1Walking/Walk_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHeroWalking.push_back(LoadTextureFromPath(strAnim.c_str()));

    }

    //Loading Hero Attack
    for(int i = 0; i < 10; i++)
    {
        std::string strAnim = "AnimTroll1Attack/Attack_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHeroBeating.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    //Loading Hero Die
    for(int i = 0; i < 10; i++)
    {
        std::string strAnim = "AnimTroll1Die/Dead_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecHeroDie.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    //Loading Enemy Attack
    for(int i = 0; i < 5; i++)
    {
        std::string strAnim = "AnimEnemyAttack/Attack_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecEnemyBeat.push_back(LoadTextureFromPath(strAnim.c_str()));
    }

    //Loading Enemy Walk
    for(int i = 0; i < 5; i++)
    {
        std::string strAnim = "AnimEnemyWalking/Walk_00";

        strAnim.append(std::to_string(i));

        strAnim.append(".png");

        m_vecEnemyWalking.push_back(LoadTextureFromPath(strAnim.c_str()));
    }
    
    //Loading Enemy Die
    for(int i = 0; i < 5; i++)
    {
        std::string strAnim = "AnimEnemyDie/Die_00";
        
        strAnim.append(std::to_string(i));
        
        strAnim.append(".png");
        
        m_vecEnemyDie.push_back(LoadTextureFromPath(strAnim.c_str()));

    }

    std::cout << "All Texture Loaded ..." << std::endl;
}

#pragma once
#include <SDL2/SDL.h>

class GameEngine
{
public:
   GameEngine(const int ScreenWidth, const int ScreenHeight);
   ~GameEngine();
    
   bool is_running();

   void CleanUp();
   void EventHandle();
   void RunGameScreen();
   void Render();

   void loadImage();

private:

    bool running;
    const int gameEngineScreenWidth , gameEngineScreenHeight;

    SDL_Window*  gameEngineWindow;
    SDL_Renderer* gameEngineRender;

    SDL_Texture* gameEngineImageTexture; 
    SDL_Surface* gameEngineSurface;

};
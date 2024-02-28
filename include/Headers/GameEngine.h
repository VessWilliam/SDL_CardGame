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
    const int e_ScreenWidth , e_ScreenHeight;

    SDL_Window*  e_Window;
    SDL_Renderer* e_Render;

    SDL_Texture* e_ImageTexture; 
    SDL_Surface* e_Surface;
};
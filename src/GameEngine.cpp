#include <SDL2/SDL.h>
#include <iostream>

#include "GameEngine.h"
#include "ErrorMessage.h"

using namespace std;

bool GameEngine::is_running()
{
    return running;
}

GameEngine::~GameEngine()
{
    CleanUp();
}

GameEngine::GameEngine(int S_Width, int S_Height)
    : e_ScreenWidth(S_Width),
      e_ScreenHeight(S_Height),
      e_Window(nullptr),
      e_Render(nullptr),
      running(false)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        ErrorMessage::showSDlError("SDL_init Message ");

    
    e_Window = SDL_CreateWindow(
        "First SDL",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        e_ScreenWidth,
        e_ScreenHeight,
        SDL_WINDOW_SHOWN);
    
   if (e_Window == NULL)
        ErrorMessage::showSDlError("Fail Create Window ");
    

    e_Render = SDL_CreateRenderer(
        e_Window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(e_Render == NULL)
        ErrorMessage::showSDlError("Fail Create Render ");


    running = true;
}

void GameEngine::CleanUp()
{
    if (e_Render != NULL)
    {
        SDL_DestroyRenderer(e_Render);
        e_Render = NULL;
    }
    if (e_Window != NULL)
    {
        SDL_DestroyWindow(e_Window);
        e_Window = NULL;
    }
    if (SDL_WasInit(SDL_INIT_VIDEO))
    {
        SDL_Quit();
    }
}

void GameEngine::Render()
{
    SDL_SetRenderDrawColor(e_Render, 0xf, 0xff, 0xff, 0xff);
    SDL_RenderClear(e_Render);
    SDL_RenderPresent(e_Render);
}


void GameEngine::EventHandle()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            running = false;
    }
}

void GameEngine::RunGameScreen()
{
    while (running)
    {
        EventHandle();
        Render();
    }
}

#include <SDL2/SDL.h>
#include <iostream>

#include "GameEngine.h"
#include "ErrorMessage.h"
#include <SDL_image.h>

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
      e_ImageTexture(nullptr),
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

    if (e_Render == NULL)
        ErrorMessage::showSDlError("Fail Create Render ");

    int ImageFlags = IMG_INIT_PNG;

    if (!(IMG_Init(ImageFlags) & ImageFlags))
        ErrorMessage::showSDlError("SDL_image could not initialize!");

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

    if (e_ImageTexture != NULL)
    {
        SDL_DestroyTexture(e_ImageTexture);
        e_ImageTexture = NULL;
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

    SDL_RenderCopy(e_Render, e_ImageTexture, NULL, NULL);

    SDL_RenderPresent(e_Render);
}

void GameEngine::loadImage()
{

    e_Surface = IMG_Load("res/Cards/cardBack_green2.png");
    if (e_Surface == NULL)
        ErrorMessage::showSDlError("Unable to load image!");

    e_ImageTexture = SDL_CreateTextureFromSurface(e_Render, e_Surface);
    if (e_ImageTexture == NULL)
        ErrorMessage::showSDlError("Unable to create texture from image!");

    SDL_FreeSurface(e_Surface);
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

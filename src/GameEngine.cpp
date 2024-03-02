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

GameEngine::GameEngine(int ScreenWidth, int ScreenHeight)
    : gameEngineScreenWidth(ScreenWidth),
      gameEngineScreenHeight(ScreenHeight),
      gameEngineWindow(nullptr),
      gameEngineRender(nullptr),
      gameEngineImageTexture(nullptr),
      running(false)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        ErrorMessage::showSDlError("SDL_init Message ");

    gameEngineWindow = SDL_CreateWindow(
        "First SDL",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        gameEngineScreenWidth,
        gameEngineScreenHeight,
        SDL_WINDOW_SHOWN);

    if (gameEngineWindow == NULL)
        ErrorMessage::showSDlError("Fail Create Window ");

    gameEngineRender = SDL_CreateRenderer(
        gameEngineWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (gameEngineRender == NULL)
        ErrorMessage::showSDlError("Fail Create Render ");

    int ImageFlags = IMG_INIT_PNG;

    if (!(IMG_Init(ImageFlags) & ImageFlags))
        ErrorMessage::showSDlError("SDL_image could not initialize!");

    running = true;
}

void GameEngine::CleanUp()
{
    if (gameEngineRender != NULL)
    {
        SDL_DestroyRenderer(gameEngineRender);
        gameEngineRender = NULL;
    }
    if (gameEngineWindow != NULL)
    {
        SDL_DestroyWindow(gameEngineWindow);
        gameEngineWindow = NULL;
    }

    if (gameEngineImageTexture != NULL)
    {
        SDL_DestroyTexture(gameEngineImageTexture);
        gameEngineImageTexture = NULL;
    }

    if (SDL_WasInit(SDL_INIT_VIDEO))
    {
        SDL_Quit();
    }
}

void GameEngine::Render()
{
    SDL_SetRenderDrawColor(gameEngineRender, 0xf, 0xff, 0xff, 0xff);
    SDL_RenderClear(gameEngineRender);

    SDL_RenderCopy(gameEngineRender, gameEngineImageTexture, NULL, NULL);

    SDL_RenderPresent(gameEngineRender);
}

void GameEngine::loadImage()
{

    gameEngineSurface = IMG_Load("res/Cards/cardBack_green2.png");
    if (gameEngineSurface == NULL)
        ErrorMessage::showSDlError("Unable to load image!");

    gameEngineImageTexture = SDL_CreateTextureFromSurface(gameEngineRender, gameEngineSurface);
    if (gameEngineImageTexture == NULL)
        ErrorMessage::showSDlError("Unable to create texture from image!");

    SDL_FreeSurface(gameEngineSurface);
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

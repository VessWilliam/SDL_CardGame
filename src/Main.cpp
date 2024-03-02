#include <iostream>
#include <SDL2/SDL.h>
#include <GameEngine.h>

using namespace std;
const int SCREEN_W = 1000, SCREEN_H = 700;

int main(int argc, char *args[])
{
     
     try
     {
       GameEngine gameEngine(SCREEN_W,SCREEN_H);
       
       gameEngine.loadImage();
       
       gameEngine.RunGameScreen();

       gameEngine.CleanUp();

     }
     catch(exception& e)
     {
        cerr << e.what() << '\n';
     }
     
    return EXIT_SUCCESS;
}
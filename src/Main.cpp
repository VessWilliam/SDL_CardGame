#include <iostream>
#include <SDL2/SDL.h>
#include <GameEngine.h>

using namespace std;
const int SCREEN_W = 800, SCREEN_H = 600;

int main(int argc, char *args[])
{
     
     try
     {
       GameEngine gameEngine(SCREEN_W,SCREEN_H);

       gameEngine.RunGameScreen();

       gameEngine.CleanUp();

     }
     catch(exception& e)
     {
        cerr << e.what() << '\n';
     }
     
    return EXIT_SUCCESS;
}
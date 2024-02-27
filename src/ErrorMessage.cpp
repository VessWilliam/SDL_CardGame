#include "ErrorMessage.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

ErrorMessage::ErrorMessage() {}

ErrorMessage::~ErrorMessage() {}

void ErrorMessage::showSDlError(string msg)
{
    cerr << msg << " SDL_Error " << SDL_GetError() << endl; 
}
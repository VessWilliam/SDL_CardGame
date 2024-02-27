#pragma once
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class ErrorMessage
{
public:
    ErrorMessage();
    ~ErrorMessage();
  
  static void showSDlError(string message);
};









// #include <iostream>
// #include <SDL2/SDL.h>

// using namespace std;
// const int SCREEN_W = 800, SCREEN_H = 600;

// int main(int argc, char *args[])
// {

//     SDL_Init(SDL_INIT_EVERYTHING);

//     SDL_Window* window = SDL_CreateWindow("First SDL",
//                                           SDL_WINDOWPOS_UNDEFINED,
//                                           SDL_WINDOWPOS_UNDEFINED,
//                                           SCREEN_W,
//                                           SCREEN_H,
//                                           SDL_WINDOW_SHOWN);

//     if (window == NULL)
//         cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;

//     SDL_Event e;

//     while (true)
//     {
//         if (SDL_PollEvent(&e))
//         {
//             if (e.type == SDL_QUIT)
//                 break;
//         }
//     }

//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return EXIT_SUCCESS;
// }
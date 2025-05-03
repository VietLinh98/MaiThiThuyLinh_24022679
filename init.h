#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool InitSDL();
void CloseSDL();

#endif

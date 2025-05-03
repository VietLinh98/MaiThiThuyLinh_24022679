#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>

extern SDL_Texture* backgroundTexture;
extern SDL_Texture* catTexture;
extern SDL_Texture* catPowerTexture;
extern SDL_Texture* obstacleTexture;
extern SDL_Texture* obstacleBrokenTexture;
extern SDL_Texture* gameOverTexture;
extern SDL_Texture* powerUpTexture;
extern SDL_Texture* playButtonTexture;
extern SDL_Texture* exitButtonTexture;
extern SDL_Texture* resumeButtonTexture;
extern SDL_Texture* restartButtonTexture;

SDL_Texture* LoadTexture(const std::string& path);
void LoadTextures();
void FreeTextures();

#endif

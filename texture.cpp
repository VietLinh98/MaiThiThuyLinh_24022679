#include "texture.h"
#include "init.h"
#include <SDL_image.h>
#include <iostream>

SDL_Texture* backgroundTexture = nullptr;
SDL_Texture* catTexture = nullptr;
SDL_Texture* catPowerTexture = nullptr;
SDL_Texture* obstacleTexture = nullptr;
SDL_Texture* obstacleBrokenTexture = nullptr;
SDL_Texture* gameOverTexture = nullptr;
SDL_Texture* powerUpTexture = nullptr;
SDL_Texture* playButtonTexture = nullptr;
SDL_Texture* exitButtonTexture = nullptr;
SDL_Texture* resumeButtonTexture = nullptr;
SDL_Texture* restartButtonTexture = nullptr;

SDL_Texture* LoadTexture(const std::string& path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) std::cout << "Error loading " << path << ": " << IMG_GetError() << std::endl;
    return texture;
}

void LoadTextures() {
    backgroundTexture = LoadTexture("background.jpg");
    catTexture = LoadTexture("cat.png");
    catPowerTexture = LoadTexture("cat_power.png");
    obstacleTexture = LoadTexture("stone.png");
    obstacleBrokenTexture = LoadTexture("stone_broken.png");
    gameOverTexture = LoadTexture("gameover.png");
    powerUpTexture = LoadTexture("powerup_box.png");
    playButtonTexture = LoadTexture("play_button.png");
    exitButtonTexture = LoadTexture("exit_button.png");
    resumeButtonTexture = LoadTexture("resume_button.png");
    restartButtonTexture = LoadTexture("restart_button.png");
}

void FreeTextures() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(catTexture);
    SDL_DestroyTexture(catPowerTexture);
    SDL_DestroyTexture(obstacleTexture);
    SDL_DestroyTexture(obstacleBrokenTexture);
    SDL_DestroyTexture(gameOverTexture);
    SDL_DestroyTexture(powerUpTexture);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(exitButtonTexture);
    SDL_DestroyTexture(resumeButtonTexture);
    SDL_DestroyTexture(restartButtonTexture);
}

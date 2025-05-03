#include "draw.h"
#include "init.h"
#include "texture.h"
#include "game.h"

void DrawScore() {
    SDL_Rect scoreBar = {800 - 200, 20, score * 5, 20};
    if (scoreColorToggle)
        SDL_SetRenderDrawColor(renderer, 255, 105, 180, 255);
    else
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &scoreBar);
}

void DrawPowerUpBar() {
    if (powerUpActive) {
        int barWidth = (powerUpActiveCounter * 200) / 600;
        SDL_Rect bar = {800 / 2 - 100, 600 - 50, barWidth, 10};
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &bar);
    }
}

void Draw() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_Rect catRect = {catX, catY, powerUpActive ? 90 : 50, powerUpActive ? 90 : 50};
    if (powerUpActive) catRect.y = 600 - 220 - (catRect.h - 50);

    SDL_RenderCopy(renderer, powerUpActive ? catPowerTexture : catTexture, NULL, &catRect);

    SDL_Rect obsRect = {obstacleX, obstacleY, 50, 50};
    SDL_RenderCopy(renderer, obstacleBroken ? obstacleBrokenTexture : obstacleTexture, NULL, &obsRect);

    if (!hasPowerUp) {
        SDL_Rect pRect = {powerUpX, powerUpY, 40, 40};
        SDL_RenderCopy(renderer, powerUpTexture, NULL, &pRect);
    }

    DrawScore();
    DrawPowerUpBar();

    if (gameOver) {
        SDL_Rect gameOverRect = {800 / 2 - 150, 600 / 2 - 100, 300, 200};
        SDL_RenderCopy(renderer, gameOverTexture, NULL, &gameOverRect);
    }

    SDL_RenderPresent(renderer);
}

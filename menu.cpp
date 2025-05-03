#include "menu.h"
#include "init.h"
#include "texture.h"
#include "game.h"

// Các nút trong menu
SDL_Rect playButtonRect    = {800 / 2 - 100, 600 / 2 - 60, 200, 50};
SDL_Rect exitButtonRect    = {800 / 2 - 100, 600 / 2 + 10, 200, 50};
SDL_Rect resumeButtonRect  = {800 / 2 - 100, 600 / 2 - 60, 200, 50};
SDL_Rect restartButtonRect = {800 / 2 - 100, 600 / 2 + 10, 200, 50};

void HandleMouseEvents(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Point mousePoint = {x, y};

        if (showMainMenu) {
            if (SDL_PointInRect(&mousePoint, &playButtonRect)) showMainMenu = false;
            if (SDL_PointInRect(&mousePoint, &exitButtonRect)) gameOver = true;
        } else if (showPauseMenu) {
            if (SDL_PointInRect(&mousePoint, &resumeButtonRect)) showPauseMenu = false;
            if (SDL_PointInRect(&mousePoint, &restartButtonRect)) ResetGame();
            if (SDL_PointInRect(&mousePoint, &exitButtonRect)) gameOver = true;
        }
    }
}

void DrawMainMenu() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
    SDL_RenderCopy(renderer, exitButtonTexture, NULL, &exitButtonRect);
    SDL_RenderPresent(renderer);
}

void DrawPauseMenu() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    SDL_RenderCopy(renderer, resumeButtonTexture, NULL, &resumeButtonRect);
    SDL_RenderCopy(renderer, restartButtonTexture, NULL, &restartButtonRect);
    SDL_RenderCopy(renderer, exitButtonTexture, NULL, &exitButtonRect);
    SDL_RenderPresent(renderer);
}

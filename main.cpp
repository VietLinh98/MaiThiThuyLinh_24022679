#include "init.h"
#include "texture.h"
#include "game.h"
#include "menu.h"
#include "draw.h"

int main(int argc, char* argv[]) {
    if (!InitSDL()) return -1;
    LoadTextures();

    while (!gameOver) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) gameOver = true;

            if (showMainMenu || showPauseMenu) {
                HandleMouseEvents(e);
            } else {
                if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_SPACE && !isJumping) {
                        isJumping = true;
                        velocityY = jumpStrength;
                    } else if (e.key.keysym.sym == SDLK_RETURN) {
                        showPauseMenu = !showPauseMenu;
                    }
                }
            }
        }

        if (showMainMenu) {
            DrawMainMenu();
        } else if (showPauseMenu) {
            DrawPauseMenu();
        } else {
            Logic();
            Draw();
        }

        SDL_Delay(16); // ~60 FPS
    }

    CloseSDL();
    return 0;
}

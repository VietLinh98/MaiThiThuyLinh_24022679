#include "game.h"
#include <SDL.h>
#include <cstdlib>

bool gameOver = false, isJumping = false;
bool showMainMenu = true, showPauseMenu = false;

int catX = 100, catY = 600 - 220;
int obstacleX = 800 - 100, obstacleY = 600 - 220;

int velocityY = 0;
const int gravity = 1;
const int jumpStrength = -15;
const int maxFallSpeed = 8;

int score = 0, speed = 5;
bool scoreColorToggle = false;

int powerUpX = 800, powerUpY = 600 - 220;
bool hasPowerUp = false, powerUpActive = false;
int powerUpActiveCounter = 600;
bool obstacleBroken = false;
int lastPowerUpScore = -10;

void ResetGame() {
    gameOver = false;
    showPauseMenu = false;
    isJumping = false;
    catX = 100;
    catY = 600 - 220;
    obstacleX = 800 - 100;
    score = 0;
    speed = 5;
    hasPowerUp = false;
    powerUpActive = false;
    obstacleBroken = false;
    powerUpX = 800;
    powerUpActiveCounter = 600;
    lastPowerUpScore = -10;
    scoreColorToggle = false;
}

void Logic() {
    if (!gameOver) {
        obstacleX -= speed;

        if (obstacleX < 0) {
            obstacleX = 800 - 100;
            score++;
            obstacleBroken = false;

            if (score % 15 == 0) speed++;
            if (score % 10 == 0 && score != lastPowerUpScore) {
                powerUpX = 800 + rand() % 300;
                hasPowerUp = false;
                lastPowerUpScore = score;
                scoreColorToggle = !scoreColorToggle;
            }
        }

        powerUpX -= speed;
        if (powerUpX < 0)
            powerUpX = 800 + rand() % 400;

        SDL_Rect catRect = {catX, catY, 50, 50};
        SDL_Rect powerUpRect = {powerUpX, powerUpY, 40, 40};

        if (SDL_HasIntersection(&catRect, &powerUpRect) && !hasPowerUp) {
            hasPowerUp = true;
            powerUpActive = true;
            powerUpX = 800;
            powerUpActiveCounter = 600;
        }

        SDL_Rect obstacleRect = {obstacleX, obstacleY, 50, 50};
        if (SDL_HasIntersection(&catRect, &obstacleRect)) {
            if (powerUpActive) obstacleBroken = true;
            else gameOver = true;
        }

        if (powerUpActive) {
            powerUpActiveCounter--;
            if (powerUpActiveCounter <= 0)
                powerUpActive = false;
        }

        if (isJumping) {
            catY += velocityY;
            velocityY += gravity;
            if (velocityY > maxFallSpeed)
                velocityY = maxFallSpeed;
            if (catY >= 600 - 220) {
                catY = 600 - 220;
                isJumping = false;
                velocityY = 0;
            }
        }
    }
}

#ifndef GAME_H
#define GAME_H

extern bool gameOver, isJumping, showMainMenu, showPauseMenu;
extern int catX, catY, obstacleX, obstacleY;
extern int velocityY;
extern const int gravity, jumpStrength, maxFallSpeed;
extern int score, speed;
extern bool scoreColorToggle;
extern int powerUpX, powerUpY;
extern bool hasPowerUp, powerUpActive;
extern int powerUpActiveCounter;
extern bool obstacleBroken;
extern int lastPowerUpScore;

void Logic();
void ResetGame();

#endif

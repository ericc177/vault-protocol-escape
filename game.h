#ifndef GAME_H
#define GAME_H

// Game states
typedef enum {
    GAME_RUNNING,
    GAME_WON,
    GAME_LOST
} GameState;

// Player structure
typedef struct {
    int hasKey;
    int attempts;
} Player;

// Function prototypes
void startGame(Player *player);
void showIntro();
void showStatus(Player *player);
int puzzleChallenge(Player *player);
GameState updateGame(Player *player);

#endif

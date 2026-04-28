#include <stdio.h>
#include "game.h"

// Intro screen
void showIntro() {
    printf("\n====================================\n");
    printf(" VAULT PROTOCOL: LOCKDOWN ESCAPE\n");
    printf("====================================\n\n");
    printf("You are trapped inside a high-security vault.\n");
    printf("Solve the system override to escape.\n\n");
}

// Show player status
void showStatus(Player *player) {
    printf("\n[STATUS]\n");
    printf("Attempts left: %d\n", 3 - player->attempts);
    printf("Key acquired: %s\n", player->hasKey ? "YES" : "NO");
}

// Puzzle logic (simple number lock)
int puzzleChallenge(Player *player) {
    int code;

    printf("\nEnter override code to unlock vault (hint: 2 + 3 * 4): ");
    scanf("%d", &code);

    player->attempts++;

    if (code == 14) {
        printf("Access granted. Key retrieved.\n");
        player->hasKey = 1;
        return 1;
    } else {
        printf("Incorrect code. Security tightening...\n");
        return 0;
    }
}

// Main game loop controller
void startGame(Player *player) {
    showIntro();

    player->hasKey = 0;
    player->attempts = 0;

    while (player->attempts < 3 && !player->hasKey) {
        showStatus(player);

        puzzleChallenge(player);

        if (player->hasKey) {
            break;
        }
    }
}

// Determine game outcome
GameState updateGame(Player *player) {
    if (player->hasKey) {
        printf("\nVAULT UNLOCKED. YOU ESCAPED.\n");
        return GAME_WON;
    } else {
        printf("\nLOCKDOWN COMPLETE. YOU FAILED TO ESCAPE.\n");
        return GAME_LOST;
    }
}

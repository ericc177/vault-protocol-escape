#include <stdio.h>
#include <string.h>

int difficulty;

// Puzzle functions
int puzzle1() {
    int answer;
    printf("\n[CONTROL ROOM TERMINAL]\n");
    printf("Enter keycard code (Hint: 1234): ");
    scanf("%d", &answer);
    return answer == 1234;
}

int puzzle2() {
    char answer[20];
    printf("\n[SECURITY AUTHENTICATION]\n");
    printf("Enter password (Hint: admin): ");
    scanf("%s", answer);
    return strcmp(answer, "admin") == 0;
}

int puzzle3() {
    int answer;
    printf("\n[SERVER ROOM POWER SYSTEM]\n");
    printf("Solve: 5 + 7 = ");
    scanf("%d", &answer);
    return answer == 12;
}

// ASCII display
void showMap() {
    printf("\nFacility Map:\n");
    printf("[C] Control Room -> [S] Security -> [R] Server -> [E] Exit\n");
}

// Main game
int main() {
    int choice;

    printf("=== VAULT PROTOCOL: LOCKDOWN ESCAPE ===\n");
    printf("1. Start Game\n2. Quit\n");
    scanf("%d", &choice);

    if (choice != 1) {
        printf("Exiting...\n");
        return 0;
    }

    // Difficulty
    printf("\nSelect Difficulty:\n1. Easy\n2. Hard\n");
    scanf("%d", &difficulty);

    showMap();

    // Puzzle 1
    while (!puzzle1()) {
        printf("Access Denied. Try again.\n");
    }

    printf("Keycard accepted. Moving to Security Office...\n");

    // Puzzle 2
    while (!puzzle2()) {
        printf("Authentication Failed. Try again.\n");
    }

    printf("Access Granted. Entering Server Room...\n");

    // Puzzle 3
    while (!puzzle3()) {
        printf("Power reroute failed. Try again.\n");
    }

    printf("\nPower rerouted successfully!\n");

    // Win screen
    printf("\n=== ESCAPE SUCCESSFUL ===\n");
    printf("You reached the Exit Airlock and escaped!\n");

    return 0;
}
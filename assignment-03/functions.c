#include <stdbool.h>
#include <stdio.h>
#include "header.h"

// Checks if there is at least one available square
bool validGame(char board[][3]) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return true;
            }
        }
    }
    return false;
}

void printGridNums(int gridNums[][3]) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("%d   ", gridNums[i][j]);
        }
        printf("\n\n");
    }
}

void fillBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("%c   ", board[i][j]);
        }
        printf("\n\n");
    }
}

// Update game board with player's shape based on player's input
int updateBoard(int gridNums[][3], char board[][3], int pos, char input) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (pos == gridNums[i][j] && board[i][j] == '-') {
                board[i][j] = input;
                return 0;
            }
        }
    }
    printf("Invalid position. Choose a valid board position.\n");
    return 1;
}

// Displays to console whichever player's turn it is, calculates the
// integer value of that input for gridNum[] comparison, and returns a player's input
void playerTurn(int currentPlayer, char input, int* pos) {
    if (currentPlayer == 0) {
        printf("Player 1 choose an available grid position: ");
    }
    else {
        printf("Player 2 choose an available grid position: ");
    }
    scanf(" %c", &input);

    // '0' ascii value is 48
    // this subtracts it from the ascii value of the grid number
    // and converts it to an integer value to compare against
    // the grid numbers
    *pos = input - '0';
}

// This function flips the current player and returns a respective player's
// "shape" to fill the game board
char changePlayerShape(int* currentPlayer, char playerShape) {

    if (*currentPlayer == 0) {
        *currentPlayer = 1;
        return playerShape = 'X';
    }
    else {
        *currentPlayer = 0;
        return playerShape = 'O';
    }
} // end getPlayerShape()

// This feels digusting and brute-force but I could not really figure out a
// more optimized way to check for a win
bool checkWin(char board[][3], int* p1, int* p2) {

    // If center piece is filled, checks for diagonal win
    if (board[1][1] == 'O') {
        if ((board[0][0] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O')) {
            printf("Player 1 wins!\n");
            (*p1)++;
            return true;
        }
    }

    // If center piece is filled, checks for other diagonal direction win
    if (board[1][1] == 'X') {
        if ((board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X')) {
            printf("Player 2 wins!\n");
            (*p2)++;
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            // Checks row for player 1 or 2 win
            if (j == 2 && board[i][j] == 'O' && board[i][j - 1] == 'O' && board[i][j - 2] == 'O') {
                printf("Player 1 wins!\n");
                (*p1)++;
                return true;
            }

            if (j == 2 && board[i][j] == 'X' && board[i][j - 1] == 'X' && board[i][j - 2] == 'X') {
                printf("Player 2 wins!\n");
                (*p2)++;
                return true;
            }

            // Checks column for player 1 or 2 win
            if (i == 2 && board[i][j] == 'O' && board[i - 1][j] == 'O' && board[i - 2][j] == 'O') {
                printf("Player 1 wins!\n");
                (*p1)++;
                return true;
            }

            if (i == 2 && board[i][j] == 'X' && board[i - 1][j] == 'X' && board[i - 2][j] == 'X') {
                printf("Player 2 wins!\n");
                (*p2)++;
                return true;
            }
        }
    }

    return false;
}

void saveScores(int p1_score, int p2_score) {
    FILE* fp;
    fp = fopen("scores.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
    }
    else {
        fprintf(fp, "Total player 1 wins: %d\n", p1_score);
        fprintf(fp, "total player 2 wins: %d\n", p2_score);
        fclose(fp);
    }
}
#include "header.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    // Array to show the users which number to enter to choose a spot
    int gridNums[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    char board[3][3];       // Array to save X & O placements as the game progresses

    int player1 = 0;        // Track player 1's wins
    int player2 = 0;        // Track player 2's wins
    char input = 0;         // User input

    int pos = 0; // Stores converted ascii value of input
    char continuePlaying = 'y'; // Flag to continue game/call saveScore() function

    printf("-----------------------\n");
    printf("----  Tic-Tac-Toe  ----\n");
    printf("-----------------------\n");

    // Game Logic
    while (continuePlaying == 'y') {
        bool valid = true; // Checks game board status
        // Binary flag to track which player's turn is active; 0 = player 1
        int currentPlayer = 0;
        char playerShape = 'O'; // Holds player shape
        bool winner = false; // Checks if a player has won

        //Print the grid numbers before the game starts (call function)
        ////Only print once at the beginning of each game
        printf("Grid Numbers:\n\n");
        printGridNums(gridNums);

        // Fill game board with dashes
        fillBoard(board);
        printf("\n\n");

        // Instance loop
        while (valid == true) {
            int position_okay = 0;

            // Displays current player, takes char input from player for grid position,
            // calculates integer value of input
            playerTurn(currentPlayer, input, &pos);

            // Update game board with player's shape based on player's input
            position_okay = updateBoard(gridNums, board, pos, playerShape);
            while (position_okay != 0) {
                playerTurn(currentPlayer, input, &pos);
                position_okay = updateBoard(gridNums, board, pos, playerShape);
            }

            // Display updated board
            printBoard(board);

            // Check if there is a winner
            winner = checkWin(board, &player1, &player2);

            // A player has won if true
            if (winner == true) {
                break;
            }

            // Used to continue game; true means there are still available
            // spaces on the board. If valid becomes false, there are no
            // space left to play and the game instance stops
            valid = validGame(board);
            if (valid == false) {
                printf("It's a tie!\n");
            }

            // Updates next player's shape
            playerShape = changePlayerShape(&currentPlayer, playerShape);
        }

        // Ask to play again
        printf("Would you like to play again (y/n)? ");
        scanf(" %c", &continuePlaying);

        if (continuePlaying == 'y') {
            system("clear");
        }

        if (continuePlaying == 'n') {
            saveScores(player1, player2);
            printf("Your scores for this session may be found at .../scores.txt\n");
        }
    }

    return 0;
}
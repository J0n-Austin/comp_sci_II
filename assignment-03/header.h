#pragma once
#include <stdbool.h>

void fillBoard(char board[][3]);
void printBoard(char board[][3]);
void printGridNums(int gridNums[][3]);
int updateBoard(int gridNums[][3], char board[][3], int pos, char input);
bool validGame(char board[][3]);
void playerTurn(int currentPlayer, char input, int* pos);
char changePlayerShape(int* currentPlayer, char playerShape);
bool checkWin(char board[][3], int* p1, int* p2);
void saveScores(int p1_score, int p2_score);
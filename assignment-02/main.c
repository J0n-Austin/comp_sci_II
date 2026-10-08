#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 30

void get_game_word(char* word);
int check_character(const char* word, char user, char* show, int flag);
void fill_show(char* show, int len);
void print_progress(char* show);
void print_hangman(const char* hang, int guesses);

int main()
{
        char hang[8] = "HANGMAN";  //letters to output for incorrect guesses
        char word[MAXCHAR];  //secret word specified before the game starts
        char show[MAXCHAR];  //starts with dashes and eventually fills up with correct letter guesses
        char user;  //user input for guessing
        int guesses = 0; // Used to track player's total guesses
        int flag = 0; // Used to determine whether player 2 guessed correctly

        printf(" ------------------------- \n");
        printf("|   H A N G M A N ! ! !   |\n");
        printf(" ------------------------- \n");

        // Get initial game word from player 1
        get_game_word(word);
        printf("You entered: %s\n", word);

        system("clear");

        int len = strlen(word) - 1;
        word[len] = '\0';
        show[len] = '\0';

        fill_show(show, len);

        while ((strcmp(word, show) != 0)) {
                flag = 0;
                printf("Secret word: ");
                print_progress(show);
                printf("Guess a letter: ");
                user = getchar();

                int flush;
                while ((flush = getchar()) != '\n' && flush != EOF) {
                }

                flag = check_character(word, user, show, flag);

                if (flag == 0) {
                        guesses++;
                        if (guesses == strlen(hang)) {
                                print_hangman(hang, guesses);
                                printf("Game over!\n");
                                return 0;
                        }
                        printf("Wrong letter!\n");
                        print_hangman(hang, guesses);
                }
        }

        printf("You did it! Game over!\n");
        printf(" ------------------------ \n");
        printf("|   H A N G M A N ! ! !  |\n");
        printf(" ------------------------ \n");
        return 0;
}

void get_game_word(char* word) {
        printf("Enter a word with fewer than 30 characters: ");
        fgets(word, MAXCHAR, stdin);
}

int check_character(const char* word, char user, char* show, int flag) {
        for (int i = 0; i < strlen(word); i++) {
                if (word[i] == user) {
                        show[i] = user;
                        flag = 1;
                }
        }
        printf("\n");
        return flag;
}

void print_progress(char* show) {
        for (int i = 0; i < strlen(show); i++) {
                printf("%c ", show[i]);
        }
        printf("\n");
}

void fill_show(char* show, int len) {
        for (int i = 0; i < len; i++) {
                show[i] = '_';
        }
}

void print_hangman(const char* hang, int guesses) {
        for (int i = 0; i < guesses; i++) {
                printf("%c ", hang[i]);
        }
        printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5

// function declarations
int num_generator(void);
void store_nums(size_t i, int rng, int* int_array_ptr);
void yes_loop(void);
void num_loop(void);
void print_num_array(int* int_array_ptr);

int main(void) {

        srand(time(0));
        char answer;
        size_t loop_counter = 0;
        int int_array[ARRAY_SIZE];
        int* int_array_ptr = int_array;

        // main program loop
        while (1) {

                loop_counter++;
                int largest = 0;

                // generate 5 random integers, store them in an array,
                // and keep track of the largest random integer
                for (size_t i = 0; i < 5; i++) {

                        int num = 0;
                        num = num_generator();
                        store_nums(i, num, int_array_ptr);

                        if (num > largest) {
                                largest = num;
                        }
                }

                // display random integer array
                printf("Random number array: ");
                print_num_array(int_array_ptr);

                // display 'yes' 5 times and the loop counter 10 times
                yes_loop();
                num_loop();

                printf("Largest integer generated: %d\n\n", largest);
                printf("Would you like to run the loop again (y/n)? ");
                scanf(" %c", &answer);

                if (answer == 'n') {
                printf("This program looped %zu times.\n", loop_counter);
                break;
                }

                printf("\n");
        }

        return 0;

} // End main()

// Generations a random integer between 1 and 50 inclusive
int num_generator(void) {
        return rand() % 50 + 1;
}

// Stores integers in an array
void store_nums(size_t i, int rng, int* int_array_ptr) {
        int_array_ptr[i] = rng;
}

// Displays integer array
void print_num_array(int* int_array_ptr) {

        for (size_t i = 0; i < ARRAY_SIZE; i++) {
                printf("%d ", int_array_ptr[i]);
        }
        printf("\n");
}

// Displays 'yes' 5 times to console
void yes_loop(void) {
        for(size_t i = 0; i < 5; i++) {
                printf("Yes\n");
        }
        printf("\n");
}

// Displays loop numbers 1 through 10 inclusive
void num_loop(void) {
        for (size_t i = 0; i < 10; i++) {
                printf("Loop number: %zu\n", i + 1);
        }
        printf("\n");
}
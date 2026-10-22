#include <stdio.h>
#include <stdlib.h>
#define DAYS 7
#define MAX_CHAR 10
#define MAX_DASHES 17

// Struct whose members store high and low temperature data for both
// Fahrenheit and Celsius
typedef struct {
    float low_f;
    float high_f;
    float low_c;
    float high_c;
} Week;

int readTemperatures(Week weekly_temps[]);
float calcCelsius(float* member);
void printDashes(void); // Break monotony 

int main (void) {
    int file_okay = 1; // Tiny error handling for fopen()
    char days_of_week[DAYS][MAX_CHAR] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    }; // Array for each day

    Week weekly_temps[DAYS]; // Initialize new structure
    // Read temperature data from temps.txt 
    file_okay = readTemperatures(weekly_temps);   

    if (file_okay) {
        for (int day = 0; day < DAYS; day++) {
            printDashes();
            printf("%s:\n", days_of_week[day]);
            printDashes();
            printf("Low of: %.0f \u00B0F\n", weekly_temps[day].low_f);
            printf("High of: %.0f \u00B0F\n", weekly_temps[day].high_f);
            printf("Low of: %.2f \u00B0C\n", weekly_temps[day].low_c);
            printf("High of: %.2f \u00B0C\n\n", weekly_temps[day].high_c);        
        }
    } else {
        printf("Error opening file.\n");
        return 0;
    }    

    return 0;
} // End main()

int readTemperatures(Week weekly_temps[]) {
    FILE* fp = fopen("temps.txt", "r");

    if (fp == NULL) {
        return 0; // Return 'false'
    }    

    // Stores data from file, performs Celsius conversion on temperatures
    for (int day = 0; day < DAYS; day++){
        fscanf(fp, "%f", &weekly_temps[day].low_f);
        weekly_temps[day].low_c = calcCelsius(&weekly_temps[day].low_f);
        fscanf(fp, "%f", &weekly_temps[day].high_f);
        weekly_temps[day].high_c = calcCelsius(&weekly_temps[day].high_f);
    }
    fclose(fp);
    return 1; // Return 'true'
} // End readTemperatures()

float calcCelsius(float* member) {
    return (*member - 32) / 1.8;
} // End calcCelsius()

void printDashes(void){
    for (int dash = 0; dash < MAX_DASHES; dash++) {
        printf("-");
    }
    printf("\n");    
} // End printDashes()

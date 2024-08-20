#include <string.h>
#include <stdlib.h>

char error_message[128] = "";

// Function to check if a string is empty or NULL
int isemptystring(const char* input) {
    return (input == NULL || input[0] == '\0');
}

// Function to check if the integer value of a string is less than 1000
int islessthanthousand(const char *input_seg) {    
    int value = atoi(input_seg);
    return (value < 1000) ? value : 0;
}

// Function to check for negative numbers in a string
int Checkifnegative(const char* input, char* delimiter) {
    char* dup_input = strdup(input);
    if (!dup_input) return -1;  // Handle strdup failure

    char* input_seg = strtok(dup_input, delimiter);
    while (input_seg) {
        if (atoi(input_seg) < 0) {
            free(dup_input);
            return -1;
        }
        input_seg = strtok(NULL, delimiter);
    }

    free(dup_input);
    return 0;
}

// Function to append custom delimiter to the delimiter string
void appendcustomdelimiter(const char* input, char* delimiter) {
    int i = 2;
    while (input[i] != '\0' && input[i] != '\n') {
        strncat(delimiter, &input[i], 1);
        i++;
    }
}

// Function to check for a custom delimiter and append it
void checkcustomdelimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        delimiter[0] = '\0'; // Clear existing delimiters
        appendcustomdelimiter(input, delimiter);
    }
}

// Function to calculate the sum of valid numbers in the input string
int calculatesum(const char* input, char* delimiter) {
    int sum = 0;
    char* dup_input = strdup(input);
    if (!dup_input) return -1;  // Handle strdup failure

    char* input_seg = strtok(dup_input, delimiter);
    while (input_seg) {
        sum += islessthanthousand(input_seg);
        input_seg = strtok(NULL, delimiter);
    }

    free(dup_input);
    return sum;
}

// Main function to add numbers based on the input string
int add(const char* input) {
    char delimiter[128] = ",\n";

    if (isemptystring(input)) {
        return 0;
    }

    checkcustomdelimiter(input, delimiter);

    if (Checkifnegative(input, delimiter) == -1) {
        strcpy(error_message, "Negative not allowed");
        return -1;
    }

    return calculatesum(input, delimiter);
}

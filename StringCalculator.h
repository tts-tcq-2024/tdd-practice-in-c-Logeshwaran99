#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_MESSAGE_SIZE 128
#define DELIMITER_SIZE 128

char error_message[ERROR_MESSAGE_SIZE] = "";

// Utility function to handle custom delimiters and return the final delimiter string
void prepare_delimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        delimiter[0] = '\0';  // Clear the default delimiter
        strncat(delimiter, &input[2], strcspn(input + 2, "\n"));
    } else {
        strcpy(delimiter, ",\n");
    }
}

// Core function to process input, calculate sum, and handle errors
int process_input(const char* input, const char* delimiter) {
    int sum = 0;
    bool negative_found = false;

    char* dup_input = strdup(input);
    if (!dup_input) {
        strcpy(error_message, "Memory allocation error");
        return -1;
    }

    char* token = strtok(dup_input, delimiter);
    while (token != NULL) {
        int value = atoi(token);
        if (value < 0) {
            negative_found = true;
            break;
        }
        if (value < 1000) {
            sum += value;
        }
        token = strtok(NULL, delimiter);
    }

    free(dup_input);

    if (negative_found) {
        strcpy(error_message, "Negative values are not allowed");
        return -1;
    }

    return sum;
}

// Main function to add numbers from a string input
int add(const char* input) {
    char delimiter[DELIMITER_SIZE];
    prepare_delimiter(input, delimiter);

    if (input == NULL || input[0] == '\0') {
        return 0;
    }

    return process_input(input, delimiter);
}

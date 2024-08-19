#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_MESSAGE_SIZE 128
#define DELIMITER_SIZE 128

char error_message[ERROR_MESSAGE_SIZE] = "";

// Utility function to check if a string is empty or null
bool is_empty_string(const char* input) {
    return (input == NULL || input[0] == '\0');
}

// Utility function to convert a string to an integer and return its value if less than 1000
int get_value_if_valid(const char *input_seg) {
    int value = atoi(input_seg);
    return (value < 1000) ? value : 0;
}

// Utility function to append custom delimiters
void append_custom_delimiter(const char* input, char* delimiter) {
    strncat(delimiter, &input[2], strcspn(input + 2, "\n"));
}

// Utility function to check for custom delimiter in input
void handle_custom_delimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        delimiter[0] = '\0';  // Clear the default delimiter
        append_custom_delimiter(input, delimiter);
    }
}

// Core function to calculate sum and handle errors
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
        sum += get_value_if_valid(token);
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
    char delimiter[DELIMITER_SIZE] = ",\n";

    if (is_empty_string(input)) {
        return 0;
    }

    handle_custom_delimiter(input, delimiter);
    return process_input(input, delimiter);
}

#include <string.h>
#include <stdlib.h>

#define ERROR_MESSAGE_SIZE 128
#define DELIMITER_SIZE 128

char error_message[ERROR_MESSAGE_SIZE] = "";

int is_empty_string(const char* input) {
    return (input == NULL || input[0] == '\0');
}

int is_less_than_thousand(const char *input_seg) {    
    int value = atoi(input_seg);
    return (value < 1000) ? value : 0;
}

int check_for_negative(const char* input, const char* delimiter) {
    char* dup_input = strdup(input);
    if (!dup_input) {
        strcpy(error_message, "Memory allocation error");
        return -1;
    }

    char* token = strtok(dup_input, delimiter);
    while (token != NULL) {
        int value = atoi(token);
        if (value < 0) {
            free(dup_input);
            return -1;
        }
        token = strtok(NULL, delimiter);
    }

    free(dup_input);
    return 0;
}

void append_custom_delimiter(const char* input, char* delimiter) {
    int i = 2; 
    while (input[i] != '\n' && input[i] != '\0') {
        strncat(delimiter, &input[i], 1);
        i++;
    }
}

void check_custom_delimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        delimiter[0] = '\0';  // Clear the default delimiter
        append_custom_delimiter(input, delimiter);
    }
}

int calculate_sum(const char* input, const char* delimiter) {
    int sum = 0;
    char* dup_input = strdup(input);
    if (!dup_input) {
        strcpy(error_message, "Memory allocation error");
        return -1;
    }

    char* token = strtok(dup_input, delimiter);
    while (token != NULL) {
        sum += is_less_than_thousand(token);
        token = strtok(NULL, delimiter);
    }

    free(dup_input);
    return sum;
}

int add(const char* input) {
    char delimiter[DELIMITER_SIZE] = ",\n";

    if (is_empty_string(input)) {
        return 0;
    }

    check_custom_delimiter(input, delimiter);

    if (check_for_negative(input, delimiter) == -1) {
        strcpy(error_message, "Negative values are not allowed");
        return -1;
    }

    return calculate_sum(input, delimiter);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define BUFFER_SIZE 100

void split(const char* str, const char* delimiter, char result[MAX_NUMBERS][BUFFER_SIZE], int* count) {
    char temp[BUFFER_SIZE];
    strcpy(temp, str);

    char* token = strtok(temp, delimiter);
    while (token != NULL) {
        strcpy(result[*count], token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
}

const char* parseDelimiter(const char* str, char delimiter[BUFFER_SIZE]) {
    if (strncmp(str, "//", 2) == 0) {
        const char* newline = strchr(str, '\n');
        if (newline != NULL) {
            int len = newline - str - 2;
            strncpy(delimiter, str + 2, len);
            delimiter[len] = '\0';
            return newline + 1;
        }
    }
    strcpy(delimiter, ",\n");
    return str;
}

int processNumber(const char* numStr) {
    int number = atoi(numStr);
    return number > 1000 ? 0 : number;
}

int calculateSum(const char* str, const char* delimiter) {
    char numbers[MAX_NUMBERS][BUFFER_SIZE];
    int count = 0;
    split(str, delimiter, numbers, &count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += processNumber(numbers[i]);
    }
    return sum;
}

int add(const char* str) {
    if (strlen(str) == 0) {
        return 0;
    }

    char delimiter[BUFFER_SIZE];
    const char* numbers = parseDelimiter(str, delimiter);

    return calculateSum(numbers, delimiter);
}

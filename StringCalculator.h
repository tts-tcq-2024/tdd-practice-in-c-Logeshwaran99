#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char error_message[128] = "";

int isemptystring(const char* input) {
    return (input == NULL || input[0] == '\0') ? 1 : 0;
}

int islessthanthousand(const char *input_seg) {    
    int value_check = atoi(input_seg);
    return (value_check < 1000) ? value_check : 0;
}

int Checkifnegative(const char* input, char* delimiter) {
    char* dup_input = strdup(input);
    char* input_seg = strtok(dup_input, delimiter);
    while (input_seg != NULL) {
        int value_check = atoi(input_seg);
        if (value_check < 0) {
            free(dup_input);
            return -1;
        }
        input_seg = strtok(NULL, delimiter);
    }
    free(dup_input);
    return 0;
}

void appendcustomdelimiter(const char* input, char* delimiter) {
    int i = 2; 
    while (input[i] != '\n') {
        char temp[2] = {input[i], '\0'}; // Use a null-terminated string
        strncat(delimiter, temp, 1);
        i++;
    }
}

void checkcustomdelimiter(const char* input, char* delimiter) {
    if (input[0] == '/' && input[1] == '/') {
        strcpy(delimiter, "");
        appendcustomdelimiter(input, delimiter);
    }
}

int calculatesum(const char* input, char* delimiter) {
    int sum = 0;
    char* dup_input = strdup(input);
    char* input_seg = strtok(dup_input, delimiter);
    while (input_seg != NULL) {
        sum += islessthanthousand(input_seg);
        input_seg = strtok(NULL, delimiter);
    }
    free(dup_input);
    return sum;
}

int add(const char* input) {
    char delimiter[128] = ",\n";
    if (isemptystring(input)) {
        return 0;
    }
    checkcustomdelimiter(input, delimiter);
    if (Checkifnegative(input, delimiter) == -1) {
        strcpy(error_message, "Negatives not allowed");
        return -1;
    }
    return calculatesum(input, delimiter);
}

int main() {
    const char* testStr = "//;\n1;2;-3;4";
    int result = add(testStr);

    if (result == -1) {
        printf("%s\n", error_message);
    } else {
        printf("Sum: %d\n", result);
    }

    return 0;
}

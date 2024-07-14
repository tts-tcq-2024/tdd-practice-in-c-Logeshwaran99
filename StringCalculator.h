#define MAX_NUMBERS 100
#define BUFFER_SIZE 100

char global_error_msg[BUFFER_SIZE];

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

int processNumber(const char* numStr, int* negatives, int* neg_count) {
    int number = atoi(numStr);
    if (number < 0) {
        negatives[(*neg_count)++] = number;
    }
    return (number <= 1000) ? number : 0;
}

void handleNegatives(int negatives[], int neg_count) {
    if (neg_count > 0) {
        strcpy(global_error_msg, "Negative numbers not allowed: ");
        for (int i = 0; i < neg_count; i++) {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "%d ", negatives[i]);
            strcat(global_error_msg, buffer);
        }
    }
}

int calculateSum(char numbers[MAX_NUMBERS][BUFFER_SIZE], int count) {
    int sum = 0;
    int negatives[MAX_NUMBERS];
    int neg_count = 0;

    for (int i = 0; i < count; i++) {
        sum += processNumber(numbers[i], negatives, &neg_count);
    }
    handleNegatives(negatives, neg_count);
    if (neg_count > 0) {
        return -1;  // Return -1 to indicate error due to negative numbers
    return sum;
}

int add(const char* str) {
    global_error_msg[0] = '\0';  // Clear the global error message
    if (str == NULL || *str == '\0') {
        return 0;
    }

    char delimiter[BUFFER_SIZE];
    str = parseDelimiter(str, delimiter);

    char numbers[MAX_NUMBERS][BUFFER_SIZE];
    int count = 0;
    split(str, delimiter, numbers, &count);

    return calculateSum(numbers, count);
}

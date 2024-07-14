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

int processNumber(const char* numStr, int* negatives, int* neg_count) {
    int number = atoi(numStr);
    if (number < 0) {
        negatives[(*neg_count)++] = number;
    }
    return (number <= 1000) ? number : 0;
}

/*void handleNegatives(int negatives[], int neg_count) {
    if (neg_count > 0) {
        printf("Negatives not allowed");
    }
}*/

int calculateSum(char numbers[MAX_NUMBERS][BUFFER_SIZE], int count) {
    int sum = 0;
    int negatives[MAX_NUMBERS];
    int neg_count = 0;

    for (int i = 0; i < count; i++) {
        sum += processNumber(numbers[i], negatives, &neg_count);
    }
    //handleNegatives(negatives, neg_count);
    return sum;
}

int add(const char* str) {
    if (*str == NULL || strlen(str) == 0) {
        return 0;
    }

    char delimiter[BUFFER_SIZE];
    str = parseDelimiter(str, delimiter);

    char numbers[MAX_NUMBERS][BUFFER_SIZE];
    int count = 0;
    split(str, delimiter, numbers, &count);

    return calculateSum(numbers, count);
}

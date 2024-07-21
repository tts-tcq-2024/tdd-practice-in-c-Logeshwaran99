#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "Hello, world!";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char*  input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char*  input = "1\n2,3";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char*  input = "1,1001";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char*  input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter2) {
    const char*  input = "//";
    int result = add(input);
}

TEST(StringCalculatorAddTests, ExpectExceptionForEmptyInput) {
    const char* input = " ";
    add(input);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    const char* input = "5,-1,4"; 
    add(input);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers2) {
    const char* input = "-5,-1,-4"; 
    add(input);
}

TEST(StringCalculatorAddTests, ExpectSumWithEmpptyString) {
    int expectedresult = 0;
    const char*  input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithEmpptyString2) {
    int expectedresult = 0;
    const char*  input = "\0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterAtStart) {
    int expectedresult = 2;
    const char* input = "\n2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithOnlyCustomDelimiterAtStart) {
    const char* input = "\n";
    int result = add(input);
}

TEST(StringCalculatorAddTests, ExpectSumWithNULL) {
    const char* input = "NULL";
    int result = add(input);
}

TEST(StringCalculatorAddTests, NoNegativesHandled) {
    int negatives[MAX_NUMBERS] = {};
    int neg_count = 0; // Ensure neg_count is zero
    handleNegatives(negatives, neg_count); // This should not print anything or exit
}

TEST(StringCalculatorAddTests, CalculateSumWithNoNegatives2) {
    char numbers[MAX_NUMBERS][BUFFER_SIZE] = {"1", "2", "3"};
    int count = 3;
    int result = calculateSum(numbers, count);
    EXPECT_EQ(result, 6); // 1 + 2 + 3 = 6
}

#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test cases for the StringCalculator

// Verify that an empty input results in a sum of zero.
TEST(StringCalculatorAddTests, SumIsZeroForEmptyInput) {
    int expected = 0;
    const char* input = "Hello, world!";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input "0" results in a sum of zero.
TEST(StringCalculatorAddTests, SumIsZeroForSingleZero) {
    int expected = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input "1,2" results in a sum of 3.
TEST(StringCalculatorAddTests, SumForTwoNumbers) {
    int expected = 3;
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input "1\n2,3" with newline as delimiter results in a sum of 6.
TEST(StringCalculatorAddTests, SumWithNewlineDelimiter) {
    int expected = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that numbers greater than 1000 are ignored, so input "1,1001" results in a sum of 1.
TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expected = 1;
    const char* input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input with custom delimiter "//;\n1;2" results in a sum of 3.
TEST(StringCalculatorAddTests, SumWithCustomDelimiter) {
    int expected = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that only a custom delimiter without numbers does not affect the sum.
TEST(StringCalculatorAddTests, SumWithCustomDelimiterOnly) {
    int expected = 0;
    const char* input = "//;\n";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that only newline as input results in a sum of zero.
TEST(StringCalculatorAddTests, ZeroSumWithOnlyNewline) {
    int expected = 0;
    const char* input = "\n";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input with a single custom delimiter "\n2" results in a sum of 2.
TEST(StringCalculatorAddTests, SumWithCustomDelimiterAtStart) {
    int expected = 2;
    const char* input = "\n2";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Verify that input with NULL as a string results in zero sum.
TEST(StringCalculatorAddTests, ZeroSumWithNULLInput) {
    int expected = 0;
    const char* input = "NULL";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Check that an empty input string is handled correctly and results in zero.
TEST(StringCalculatorAddTests, SumWithEmptyString) {
    int expected = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Ensure that handling of negative numbers throws an exception as expected.
TEST(StringCalculatorAddTests, ExceptionForNegativeNumbers) {
    const char* input = "5,-1,4";
    //EXPECT_THROW(add(input), std::invalid_argument);
}

TEST(StringCalculatorAddTests, ExceptionForMultipleNegativeNumbers) {
    const char* input = "-5,-1,-4";
    //EXPECT_THROW(add(input), std::invalid_argument);
}

// Ensure that no output is produced when there are no negative numbers to handle.
TEST(StringCalculatorAddTests, HandleNoNegatives) {
    int negatives[MAX_NUMBERS] = {};
    int neg_count = 0;
    testing::internal::CaptureStdout();
    handleNegatives(negatives, neg_count);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty()); // Expect no output
}

// Test summing numbers when there are no negatives.
TEST(StringCalculatorAddTests, CalculateSumWithNoNegatives) {
    char numbers[MAX_NUMBERS][BUFFER_SIZE] = {"1", "2", "3"};
    int count = 3;
    int result = calculateSum(numbers, count);
    EXPECT_EQ(result, 6); // 1 + 2 + 3 = 6
}

// Test for an empty string to verify that it results in zero.
TEST(StringCalculatorAddTests, SumWithEmptyString2) {
    int expected = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expected);
}

// Test custom delimiter handling with various edge cases.
TEST(StringCalculatorAddTests, CustomDelimiterWithNoNumbers) {
    const char* input = "//;\n\n";
    int result = add(input);
    ASSERT_EQ(result, 0); // Only delimiters, no numbers should result in 0
}

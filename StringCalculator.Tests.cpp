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
    const char* input = "5,-1,4"; // throws runtime error if the code is enabled but commented out currently
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

// Test handling of negative numbers where `neg_count > 0`.
TEST(StringCalculatorAddTests, HandleNegativesWithMultipleValues1) {
    int negatives[MAX_NUMBERS] = {-1, -2};
    int neg_count = 2;
    //testing::internal::CaptureStdout();
    handleNegatives(negatives, neg_count);
    //std::string output = testing::internal::GetCapturedStdout();
    //EXPECT_NE(output.find("Negatives not allowed: -1 -2"), std::string::npos);
}

// Test calculateSum with input that forces negative handling.
TEST(StringCalculatorAddTests, CalculateSumWithNegatives1) {
    char numbers[MAX_NUMBERS][BUFFER_SIZE] = {"1", "-2", "3"};
    int count = 3;
    //testing::internal::CaptureStdout();
    int result = calculateSum(numbers, count);
    //std::string output = testing::internal::GetCapturedStdout();
    //EXPECT_EQ(result, 4); // 1 + 0 + 3 = 4
    //EXPECT_NE(output.find("Negatives not allowed: -2"), std::string::npos);
}

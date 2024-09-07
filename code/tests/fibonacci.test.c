#include "../deps/unity_testing_library/src/unity.h"
#include "../src/fibonacci.h"

void setUp(void) {}

void tearDown(void) {}

void recShouldReturnOne(void) {
  // Arrange
  int input1 = 0; int input2 = 1;
  // Act
  int result1 = fibonacciRec(input1);
  int result2 = fibonacciRec(input2);
  // Assert
  TEST_ASSERT_EQUAL_INT(1, result1);
  TEST_ASSERT_EQUAL_INT(1, result2);
}

void recShouldComputeFibonacciCorrectly(void) {
  // Arrange
  int input1 = 2; int input2 = 5; int input3 = 9; int input4 = 13;
  // Act
  int result1 = fibonacciRec(input1);
  int result2 = fibonacciRec(input2);
  int result3 = fibonacciRec(input3);
  int result4 = fibonacciRec(input4);
  // Assert
  TEST_ASSERT_EQUAL_INT(2, result1);
  TEST_ASSERT_EQUAL_INT(8, result2);
  TEST_ASSERT_EQUAL_INT(55, result3);
  TEST_ASSERT_EQUAL_INT(377, result4);
}

void recShouldNotAcceptNegativeInput(void) {
  // Arrange
  int input1 = -5;
  // Act
  int result1 = fibonacciRec(input1);
  // Assert
  TEST_ASSERT_EQUAL_INT(NEGATIVE_INPUT_ERRNO, result1);
}

void memoShouldReturnOne(void) {
  // Arrange
  int input1 = 0; int input2 = 1;
  // Act
  int result1 = fibonacciMemo(input1);
  int result2 = fibonacciMemo(input2);
  // Assert
  TEST_ASSERT_EQUAL_INT(1, result1);
  TEST_ASSERT_EQUAL_INT(1, result2);
}

void memoShouldComputeFibonacciCorrectly(void) {
  // Arrange
  int input1 = 2; int input2 = 5; int input3 = 9; int input4 = 13;
  // Act
  int result1 = fibonacciMemo(input1);
  int result2 = fibonacciMemo(input2);
  int result3 = fibonacciMemo(input3);
  int result4 = fibonacciMemo(input4);
  // Assert
  TEST_ASSERT_EQUAL_INT(2, result1);
  TEST_ASSERT_EQUAL_INT(8, result2);
  TEST_ASSERT_EQUAL_INT(55, result3);
  TEST_ASSERT_EQUAL_INT(377, result4);
}

void memoShouldNotAcceptNegativeInput(void) {
  // Arrange
  int input1 = -5;
  // Act
  int result1 = fibonacciMemo(input1);
  // Assert
  TEST_ASSERT_EQUAL_INT(NEGATIVE_INPUT_ERRNO, result1);
}

int main(void) {
  UNITY_BEGIN();
    RUN_TEST(recShouldReturnOne);
    RUN_TEST(recShouldComputeFibonacciCorrectly);
    RUN_TEST(recShouldNotAcceptNegativeInput);
    RUN_TEST(memoShouldReturnOne);
    RUN_TEST(memoShouldComputeFibonacciCorrectly);
    RUN_TEST(memoShouldNotAcceptNegativeInput);
  return UNITY_END();
}

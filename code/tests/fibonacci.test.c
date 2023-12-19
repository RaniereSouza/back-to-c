#include "../deps/Unity-2.5.2/src/unity.h"
#include "../src/fibonacci.h"

void setUp(void) {}

void tearDown(void) {}

void it_should_return_one(void) {
  // Arrange
  int input1 = 0; int input2 = 1;
  // Act
  int result1 = fibonacci(input1);
  int result2 = fibonacci(input2);
  // Assert
  TEST_ASSERT_EQUAL_INT(1, result1);
  TEST_ASSERT_EQUAL_INT(1, result2);
}

void it_should_compute_fibonacci_correctly(void) {
  // Arrange
  int input1 = 2; int input2 = 5; int input3 = 9; int input4 = 13;
  // Act
  int result1 = fibonacci(input1);
  int result2 = fibonacci(input2);
  int result3 = fibonacci(input3);
  int result4 = fibonacci(input4);
  // Assert
  TEST_ASSERT_EQUAL_INT(2, result1);
  TEST_ASSERT_EQUAL_INT(8, result2);
  TEST_ASSERT_EQUAL_INT(55, result3);
  TEST_ASSERT_EQUAL_INT(377, result4);
}

void it_should_not_accept_negative_input(void) {
  // Arrange
  int input1 = -5;
  // Act
  int result1 = fibonacci(input1);
  // Assert
  TEST_ASSERT_EQUAL_INT(INVALID_INPUT_ERRNO, result1);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(it_should_return_one);
  RUN_TEST(it_should_compute_fibonacci_correctly);
  RUN_TEST(it_should_not_accept_negative_input);
  return UNITY_END();
}

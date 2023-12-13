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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(it_should_return_one);
  return UNITY_END();
}

#include "../deps/unity_testing_library/src/unity.h"
#include "../src/dynamic_array.h"

void setUp(void) {}

void tearDown(void) {}

void it_should_create_push_and_get() {
  // Arrange
  IntArray arr = create_int_array();
  // Assert
  TEST_ASSERT_EQUAL_INT(0, arr.len);
  TEST_ASSERT(arr.ptr == NULL);
  // Act
  int_array_push(42, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(1, arr.len);
  TEST_ASSERT_EQUAL_INT(42, int_array_get(0, &arr));
  //Act
  int_array_push(69, &arr);
  int_array_push(13, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(3, arr.len);
  TEST_ASSERT_EQUAL_INT(69, int_array_get(1, &arr));
  TEST_ASSERT_EQUAL_INT(13, int_array_get(2, &arr));
}

void it_should_not_get_from_empty_array() {
  // Arrange
  IntArray arr = create_int_array();
  // Act
  int result = int_array_get(0, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(ACCESS_EMPTY_ARR_ERRNO, result);
}

void it_should_not_get_out_of_range_index() {
  // Arrange
  IntArray arr = create_int_array();
  int_array_push(42, &arr);
  // Act
  int result = int_array_get(1, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(OUT_OF_RANGE_ARR_ERRNO, result);
}

void it_should_not_get_negative_index() {
  // Arrange
  IntArray arr = create_int_array();
  int_array_push(42, &arr);
  // Act
  int result = int_array_get(-1, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(NEGATIVE_INDEX_ARR_ERRNO, result);
}

void it_should_clear_the_array() {
  // Arrange
  IntArray arr = create_int_array();
  int_array_push(42, &arr);
  int_array_push(69, &arr);
  int_array_push(13, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(3, arr.len);
  TEST_ASSERT_EQUAL_INT(42, int_array_get(0, &arr));
  TEST_ASSERT_EQUAL_INT(69, int_array_get(1, &arr));
  TEST_ASSERT_EQUAL_INT(13, int_array_get(2, &arr));
  // Act
  int_array_clean(&arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(0, arr.len);
  TEST_ASSERT(arr.ptr == NULL);
}

int main(void) {
  UNITY_BEGIN();
    RUN_TEST(it_should_create_push_and_get);
    RUN_TEST(it_should_not_get_from_empty_array);
    RUN_TEST(it_should_not_get_out_of_range_index);
    RUN_TEST(it_should_not_get_negative_index);
    RUN_TEST(it_should_clear_the_array);
  return UNITY_END();
}

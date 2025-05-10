#include "../deps/unity_testing_library/src/unity.h"
#include "../src/dynamic_array.h"

void setUp(void) {}

void tearDown(void) {}

void itShouldCreatePushAndGet() {
  // Arrange
  IntArray arr = createIntArray();
  // Assert
  TEST_ASSERT_EQUAL_INT(0, arr.len);
  TEST_ASSERT(arr.ptr == NULL);
  // Act
  intArrayPush(42, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(1, arr.len);
  TEST_ASSERT_EQUAL_INT(42, intArrayGet(0, &arr));
  //Act
  intArrayPush(69, &arr);
  intArrayPush(13, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(3, arr.len);
  TEST_ASSERT_EQUAL_INT(42, intArrayGet(0, &arr));
  TEST_ASSERT_EQUAL_INT(69, intArrayGet(1, &arr));
  TEST_ASSERT_EQUAL_INT(13, intArrayGet(2, &arr));
}

void itShouldNotGetFromEmptyArray() {
  // Arrange
  IntArray arr = createIntArray();
  // Act
  int result = intArrayGet(0, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(ACCESS_EMPTY_ARR_ERRNO, result);
}

void itShouldNotGetOutOfRangeIndex() {
  // Arrange
  IntArray arr = createIntArray();
  intArrayPush(42, &arr);
  // Act
  int result = intArrayGet(1, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(OUT_OF_RANGE_ARR_ERRNO, result);
}

void itShouldNotGetNegativeIndex() {
  // Arrange
  IntArray arr = createIntArray();
  intArrayPush(42, &arr);
  // Act
  int result = intArrayGet(-1, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(NEGATIVE_INDEX_ARR_ERRNO, result);
}

void itShouldClearTheArray() {
  // Arrange
  IntArray arr = createIntArray();
  intArrayPush(42, &arr);
  intArrayPush(69, &arr);
  intArrayPush(13, &arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(3, arr.len);
  TEST_ASSERT_EQUAL_INT(42, intArrayGet(0, &arr));
  TEST_ASSERT_EQUAL_INT(69, intArrayGet(1, &arr));
  TEST_ASSERT_EQUAL_INT(13, intArrayGet(2, &arr));
  // Act
  intArrayClean(&arr);
  // Assert
  TEST_ASSERT_EQUAL_INT(0, arr.len);
  TEST_ASSERT(arr.ptr == NULL);
  TEST_ASSERT_EQUAL_INT(ACCESS_EMPTY_ARR_ERRNO, intArrayGet(0, &arr));
  TEST_ASSERT_EQUAL_INT(ACCESS_EMPTY_ARR_ERRNO, intArrayGet(1, &arr));
  TEST_ASSERT_EQUAL_INT(ACCESS_EMPTY_ARR_ERRNO, intArrayGet(2, &arr));
}

int main(void) {
  UNITY_BEGIN();
    RUN_TEST(itShouldCreatePushAndGet);
    RUN_TEST(itShouldNotGetFromEmptyArray);
    RUN_TEST(itShouldNotGetOutOfRangeIndex);
    RUN_TEST(itShouldNotGetNegativeIndex);
    RUN_TEST(itShouldClearTheArray);
  return UNITY_END();
}

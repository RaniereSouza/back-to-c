#ifndef __DYNAMIC_ARRAY_MODULE__
#define __DYNAMIC_ARRAY_MODULE__
/**
 * Fail output that indicates that there was an attempt to access a value from an empty array
 */
#define ACCESS_EMPTY_ARR_ERRNO -1

/**
 * Fail output that indicates that there was an attempt to access a value from an index outside of the array
 */
#define OUT_OF_RANGE_ARR_ERRNO -2

/**
 * Fail output that indicates that there was an attempt to access a negative index in the array
 */
#define NEGATIVE_INDEX_ARR_ERRNO -3

/**
 * Represents a dynamic array of int and it's length
 */
typedef struct IntArray {
  int *ptr;
  int len;
} IntArray;

/**
 * Creates an empty dynamic array of int
 */
IntArray createIntArray();

/**
 * Pushes a new int into the last position of the array
 */
void intArrayPush(int newItem, IntArray* array);

/**
 * Gets the value from a certain index in the array
 */
int intArrayGet(int index, IntArray* array);

/**
 * Empty the array and free it's allocated memory
 */
void intArrayClean(IntArray* array);
#endif
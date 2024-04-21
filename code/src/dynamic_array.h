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
typedef struct {
  int *ptr;
  int len;
} IntArray;

/**
 * Creates an empty dynamic array of int
 */
IntArray create_int_array();

/**
 * Pushes a new int into the last position of the array
 */
void int_array_push(int new_item, IntArray* array);

/**
 * Gets the value from a certain index in the array
 */
int int_array_get(int index, IntArray* array);
#endif
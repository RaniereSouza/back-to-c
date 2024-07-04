#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

IntArray createIntArray() {
  IntArray array;

  array.ptr = NULL;
  array.len = 0;

  return array;
}

void intArrayPush(int newItem, IntArray* array) {
  if (array->ptr == NULL) array->ptr = (int*) malloc(sizeof(int));
  else array->ptr = (int*) realloc(array->ptr, (array->len + 1) * sizeof(int));

  array->ptr[array->len] = newItem;
  array->len++;
}

int intArrayGet(int index, IntArray* array) {
  if (index < 0) {
    fprintf(stderr, "[ERROR] tried to access a negative index in the array.\n");
    return NEGATIVE_INDEX_ARR_ERRNO;
  }

  if ((array->ptr == NULL) || (array->len == 0)) {
    fprintf(stderr, "[ERROR] tried to get value from empty array.\n");
    return ACCESS_EMPTY_ARR_ERRNO;
  }

  if (index >= array->len) {
    fprintf(stderr, "[ERROR] tried to get value out of the array index range.\n");
    return OUT_OF_RANGE_ARR_ERRNO;
  }

  return array->ptr[index];
}

void intArrayClean(IntArray* array) {
  if (array->len) array->len = 0;
  if (array->ptr != NULL) {
    free(array->ptr);
    array->ptr = NULL;
  }
}

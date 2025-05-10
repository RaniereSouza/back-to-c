#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"
#include "fibonacci.h"

int fibonacciRec(int n) {
  if (n < 0) {
    fprintf(
      stderr,
      "[ERROR] argument for Fibonacci should be a positive integer, received %d.\n",
      n
    );
    return NEGATIVE_INPUT_ERRNO;
  }
  if ((n == 0) || (n == 1)) return 1;
  return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int __fibMemoRec(int n, IntArray *memo) {
  if (n >= memo->len) {
    intArrayPush(__fibMemoRec(n - 1, memo) + __fibMemoRec(n - 2, memo), memo);
  }
  return intArrayGet(n, memo);
}

int fibonacciMemo(int n) {
  if (n < 0) {
    fprintf(
      stderr,
      "[ERROR] argument for Fibonacci should be a positive integer, received %d.\n",
      n
    );
    return NEGATIVE_INPUT_ERRNO;
  }
  if ((n == 0) || (n == 1)) return 1;

  IntArray memo = createIntArray();
  intArrayPush(1, &memo); intArrayPush(1, &memo);

  int result = __fibMemoRec(n, &memo);
  intArrayClean(&memo);
  return result;
}

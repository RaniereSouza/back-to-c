#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"
#include "fibonacci.h"

int fibonacci_rec(int n) {
  if (n < 0) {
    fprintf(
      stderr,
      "[ERROR] argument for Fibonacci should be a positive integer, received %d.\n",
      n
    );
    return INVALID_INPUT_ERRNO;
  }
  if ((n == 0) || (n == 1)) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int __fib_memo_rec(int n, IntArray *memo) {
  if (n >= memo->len) {
    int_array_push(__fib_memo_rec(n - 1, memo) + __fib_memo_rec(n - 2, memo), memo);
  }
  return int_array_get(n, memo);
}

int fibonacci(int n) {
  if (n < 0) {
    fprintf(
      stderr,
      "[ERROR] argument for Fibonacci should be a positive integer, received %d.\n",
      n
    );
    return INVALID_INPUT_ERRNO;
  }

  IntArray memo = create_int_array();
  int_array_push(1, &memo);
  int_array_push(1, &memo);

  if ((n == 0) || (n == 1)) return int_array_get(n, &memo);
  return __fib_memo_rec(n, &memo);
}

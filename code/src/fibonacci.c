#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

int fibonacci(int n) {
  if (n < 0) {
    fprintf(
      stderr,
      "argument for Fibonacci should be a positive integer, received %d.\n",
      n
    );
    return INVALID_INPUT_ERRNO;
  }
  if ((n == 0) || (n == 1)) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// int fibonacci_memo(int n) { ... }

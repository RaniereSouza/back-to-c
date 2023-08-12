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
    return -1;
  }
  if ((n == 0) || (n == 1)) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// int fibonacci_memo(int n) { ... }

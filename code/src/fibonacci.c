#include <stdio.h>
#include <stdlib.h>

#ifndef __FIBONACCI_MODULE__
#define __FIBONNACI_MODULE__
/**
 * Fibonacci with recursion
 */
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

/**
 * TODO: Fibonnaci with memoization
 */
// int fibonacci_memo(int n) { ... }
#endif

#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

int main() {
  int input = -3;
  int result = fibonacci(input);

  if (result < 0) return EXIT_FAILURE;

  printf("the #%d Fibonacci number is the number %d.\n", input, result);
  return EXIT_SUCCESS;
}

#include <stdio.h>

#include "fibonacci.c"

void main() {
  int input = -3;
  int result = fibonacci(input);

  if (result < 0) exit(EXIT_FAILURE);

  printf("the #%d Fibonacci number is the number %d.\n", input, result);
  exit(EXIT_SUCCESS);
}

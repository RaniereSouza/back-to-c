#ifndef __FIBONACCI_MODULE__
#define __FIBONACCI_MODULE__
/**
 * Fail output that indicates that an invalid negative input was received
 */
#define NEGATIVE_INPUT_ERRNO -1

/**
 * Fibonacci with only recursion
 */
int fibonacciRec(int n);

/**
 * Fibonnaci with memoization
 */
int fibonacciMemo(int n);
#endif

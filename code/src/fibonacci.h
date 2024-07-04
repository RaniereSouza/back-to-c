#ifndef __FIBONACCI_MODULE__
#define __FIBONNACI_MODULE__
/**
 * Fail output that indicates that a received argument wasn't acceptable
 */
#define INVALID_INPUT_ERRNO -1

/**
 * Fibonacci with recursion
 */
int fibonacciRec(int n);

/**
 * Fibonnaci with memoization
 */
int fibonacciMemo(int n);
#endif

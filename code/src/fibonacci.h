#ifndef __FIBONACCI_MODULE__
#define __FIBONACCI_MODULE__
/**
 * Fail output that indicates that a received argument wasn't acceptable
 */
#define INVALID_INPUT_ERRNO -1

/**
 * Fibonacci with recursion
 */
int fibonacci_rec(int n);

/**
 * Fibonnaci with memoization
 */
int fibonacci_memo(int n);
#endif

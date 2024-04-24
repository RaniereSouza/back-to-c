#include <stdio.h>
#include <stdlib.h>

// #include "fibonacci.h"
//
// int main() {
//   printf("insert an integer n to get the nth Fibonacci number: ");
//
//   int input;
//   scanf("%d", &input);
//
//   int result = fibonacci_memo(input);
//   if (result == INVALID_INPUT_ERRNO) return EXIT_FAILURE;
//
//   printf("the #%d Fibonacci number is the number %d.\n", input, result);
//   return EXIT_SUCCESS;
// }

#include "../deps/raylib_5/src/raylib.h"

int main(void) {
  InitWindow(800, 450, "First successful window created!");

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Hello, Raylib 5!", 320, 200, 20, GRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

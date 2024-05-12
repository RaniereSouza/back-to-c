#include <stdio.h>
#include <string.h>

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
#include "../deps/raylib_5/src/raygui.h"

#define MAX_STRING_SIZE 255

int main(void) {
  // CONFIG
  int fps = 60;
  int windowWidth = 800;
  int windowHeight = 450;
  Color windowBgColor = RAYWHITE;
  Color textDefaultColor = GRAY;

  // STATE
  int count = 0;
  char countStr[3];
  snprintf(countStr, sizeof(countStr), "%d", count);
  char buttonMessageBase[MAX_STRING_SIZE] = "CLICK COUNT: ";
  char buttonMessage[MAX_STRING_SIZE] = "";

  // GUI
  SetTargetFPS(fps);
  InitWindow(windowWidth, windowHeight, "First successful window created!");
    while (!WindowShouldClose()) {
      BeginDrawing();
        ClearBackground(windowBgColor);
        DrawText("Hello, Raylib 5!", 320, 200, 20, textDefaultColor);

        strcpy(buttonMessage, buttonMessageBase);
        if (GuiButton((Rectangle){ 320, 240, 145, 45 }, strcat(buttonMessage, countStr))) {
          printf("DEBUG: COUNT BUTTON PRESSED!\n");
          snprintf(countStr, sizeof(countStr), "%d", ++count);
        }
      EndDrawing();
    }
  CloseWindow();

  return 0;
}

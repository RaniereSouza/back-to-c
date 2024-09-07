// #include "fibonacci.h"
//
// int main() {
//   printf("insert an integer n to get the nth Fibonacci number: ");
//
//   int input;
//   scanf("%d", &input);
//
//   int result = fibonacciMemo(input);
//   if (result == NEGATIVE_INPUT_ERRNO) return EXIT_FAILURE;
//
//   printf("the #%d Fibonacci number is the number %d.\n", input, result);
//   return EXIT_SUCCESS;
// }

#include <stdio.h>
#include <string.h>

#include "../deps/raylib_5/src/raylib.h"
#include "../deps/raylib_5/src/raygui.h"

// #include "fibonacci.h"

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
  char buttonMessage[MAX_STRING_SIZE];
  char inputText[MAX_STRING_SIZE];

  // GUI
  SetTargetFPS(fps);
  InitWindow(windowWidth, windowHeight, "First successful window created!");
    while (!WindowShouldClose()) {
      BeginDrawing();
        ClearBackground(windowBgColor);
        DrawText("Hello, Raylib 5!", 330, 160, 20, textDefaultColor);

        strcpy(buttonMessage, buttonMessageBase);
        strcat(buttonMessage, countStr);
        if (GuiButton((Rectangle){ 330, 200, 145, 45 }, buttonMessage)) {
          printf("DEBUG: count button pressed!\n");
          snprintf(countStr, sizeof(countStr), "%d", ++count);
        }

        if (
          GuiTextBox((Rectangle){ 330, 260, 145, 45 }, inputText, MAX_STRING_SIZE, true)
          && IsKeyPressed(KEY_ENTER)
        ) {
          printf("DEBUG: text input content is \"%s\"\n", inputText);
        }
      EndDrawing();
    }
  CloseWindow();

  return 0;
}

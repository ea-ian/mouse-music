#include <windows.h>
#include <stdio.h>

int main() {
    struct POINT cursorPos;
    if (GetCursorPos(&cursorPos)) {
        printf("Cursor Position: X = %d, Y = %d\n", cursorPos.x, cursorPos.y);
    } else {
        printf("Failed to get cursor position.\n");
    }
    return 0;
}

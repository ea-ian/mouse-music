#include <stdio.h>
#include "terminal.c"

int main() {
    struct cursor cursor_pos;
    cursor_pos = get_cursor();
    if (cursor_pos.x == -1) {
        return 1;
    }

    printf("mouse position:(%d, %d)\n",
            cursor_pos.x,
            cursor_pos.y);

    return 0;
}

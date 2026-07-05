#include <stdio.h>

struct cursor {
    int x;
    int y;
};

#ifdef _WIN32
    /* ========== Windows ========== */
#include <windows.h>
struct cursor get_cursor(void) {
    struct cursor cursor_pos;
    POINT point;
    if (GetCursorPos(&point)) {
        cursor_pos.x = point.x;
        cursor_pos.y = point.y;
        return cursor_pos;
    }
    else {
        struct cursor err;
        err.x = -1;
        err.y = -1;
        fprintf(stderr, "無法獲取鼠標位置\n");
        return err;
    }
}

#else
    /* ========== Linux ========== */
#include <X11/Xlib.h>
struct cursor get_cursor(void) {
    struct cursor cursor_pos;
    Display *display;
    Window root, child;
    int root_x, root_y, win_x, win_y;
    unsigned int mask;

    // 打開 X display
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "無法打開 X display\n");
        struct cursor err;
        err.x = -1;
        err.y = -1;
        fprintf(stderr, "無法獲取鼠標位置\n");
        return err;

    }

    // 獲取根窗口
    root = DefaultRootWindow(display);

    // 查詢鼠標位置
    if (XQueryPointer(display, root, &root, &child,
                      &root_x, &root_y, &win_x, &win_y, &mask)) {
        cursor_pos.x = root_x;
        cursor_pos.y = root_y;
        return cursor_pos;
    } else {
        fprintf(stderr, "無法獲取鼠標位置\n");
        struct cursor err;
        err.x = -1;
        err.y = -1;
        fprintf(stderr, "無法獲取鼠標位置\n");
        return err;

    }

    XCloseDisplay(display);
 
}
#endif

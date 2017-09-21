#include "stdafx.h"

int main() {
    char c = 'Q';
    char *char_pointer = &c;

    printf("%c %c", c, *char_pointer);
    getchar();
    return 0;
}

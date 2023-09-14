#include <stdio.h>

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

typedef int IntColor;

int main() {
    Color myColor = GREEN;
    IntColor myIntColor = 42;
    printf("Enum Color: %d, Integer Color: %d\n", myColor, myIntColor);
    return 0;
}

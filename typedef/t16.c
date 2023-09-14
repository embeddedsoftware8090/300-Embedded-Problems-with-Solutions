#include <stdio.h>

typedef signed char MySignedChar;
typedef unsigned char MyUnsignedChar;

int main() {
    MySignedChar a = -1;
    MyUnsignedChar b = 255;
    printf("Signed Char: %d, Unsigned Char: %u\n", a, b);
    return 0;
}

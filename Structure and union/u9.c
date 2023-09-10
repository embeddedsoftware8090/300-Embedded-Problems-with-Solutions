#include <stdio.h>

union Data {
    unsigned char bytes[4];
    int integer;
    float floatingPoint;
};

int main() {
    union Data data;
    data.bytes[0] = 0x00;
    data.bytes[1] = 0x00;
    data.bytes[2] = 0x48;
    data.bytes[3] = 0x43;

    printf("I/P: Bytes: [0x43, 0x48, 0x00, 0x00]\n");
    printf("O/P: Float: %.1f\n", data.floatingPoint);

    return 0;
}

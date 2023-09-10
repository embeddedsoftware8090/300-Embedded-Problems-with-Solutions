#include <stdio.h>

// Original structure
struct Original {
    int num;    // 4 bytes (assuming int is 4 bytes)
    char ch;    // 1 byte
    short sh;   // 2 bytes
};

// Optimized structure
struct Optimized {
    char ch;    // 1 byte
    short sh;   // 2 bytes
    int num;    // 4 bytes
};

int main() {
    printf("Input: Structure with members in the order - int, char, short\n");
    printf("Output: Original Memory Size: %lu bytes; Optimized Memory Size: %lu bytes\n", sizeof(struct Original), sizeof(struct Optimized));

    return 0;
}

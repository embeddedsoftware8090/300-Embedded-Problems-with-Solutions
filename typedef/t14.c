#include <stdio.h>

typedef int Matrix[3][3];

int main() {
    Matrix identity = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    printf("Identity matrix element (1,1): %d\n", identity[0][0]);
    return 0;
}

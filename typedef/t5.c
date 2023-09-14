#include <stdio.h>

typedef int* IntPtr;

int main() {
    int num = 42;
    IntPtr p = &num;
    printf("Value through pointer: %d\n", *p);
    return 0;
}

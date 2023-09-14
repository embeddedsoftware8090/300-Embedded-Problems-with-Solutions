#include <stdio.h>

typedef int (*MathFunc)(int, int);

int add(int a, int b) {
    return a + b;
}

int main() {
    MathFunc func = add;
    int result = func(5, 3);
    printf("Result of addition: %d\n", result);
    return 0;
}

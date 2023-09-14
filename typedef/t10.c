#include <stdio.h>

typedef int (*ArithmeticFunc)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    ArithmeticFunc func;
    func = add;
    printf("Addition: %d\n", func(5, 3));
    func = subtract;
    printf("Subtraction: %d\n", func(5, 3));
    return 0;
}

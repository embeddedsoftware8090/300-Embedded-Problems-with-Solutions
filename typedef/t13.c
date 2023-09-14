#include <stdio.h>

typedef int* IntPtrFunc(int);

int* doubleValue(int x) {
    int* result = malloc(sizeof(int));
    *result = x * 2;
    return result;
}

int main() {
    IntPtrFunc* func = doubleValue;
    int* result = func(5);
    printf("Doubled value: %d\n", *result);
    free(result);
    return 0;
}

#include <stdio.h>

typedef int* (*FuncReturningIntPtr)();

int* createIntArray() {
    int* arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    FuncReturningIntPtr func = createIntArray;
    int* arr = func();
    printf("Array elements: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
    return 0;
}

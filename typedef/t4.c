#include <stdio.h>

typedef int IntArray[5];

int main() {
    IntArray arr = {1, 2, 3, 4, 5};
    printf("Array elements: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    return 0;
}

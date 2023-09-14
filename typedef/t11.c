
#include <stdio.h>

typedef int (*IntArrayPtr)[5];

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    IntArrayPtr ptr = &arr;
    printf("First element: %d\n", (*ptr)[0]);
    return 0;
}

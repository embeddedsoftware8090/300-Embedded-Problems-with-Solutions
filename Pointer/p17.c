#include <stdio.h>

int calculateDotProduct(const int *vec1, const int *vec2, int length) {
    int dotProduct = 0;

    for (int i = 0; i < length; i++) {
        dotProduct += vec1[i] * vec2[i];
    }

    return dotProduct;
}

int main() {
    int vec1[] = {1, 2, 3};
    int vec2[] = {4, 5, 6};
    int length = sizeof(vec1) / sizeof(vec1[0]);

    int result = calculateDotProduct(vec1, vec2, length);

    printf("Dot Product: %d\n", result);

    return 0;
}

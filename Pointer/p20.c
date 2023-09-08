
#include <stdio.h>

// Function to flatten a 2D array into a 1D array
void flattenArray(int arr[][2], int m, int n, int flatArr[]) {
    int* flatPtr = flatArr; // Pointer to the flat array

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *flatPtr = arr[i][j]; // Copy the element to the flat array
            flatPtr++; // Move the flat array pointer to the next position
        }
    }
}

int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    int m = 2; // Number of rows
    int n = 2; // Number of columns
    int flatArr[m * n]; // 1D array to store flattened elements

    // Flatten the 2D array into the 1D array
    flattenArray(arr, m, n, flatArr);

    printf("Flattened Array: {");
    for (int i = 0; i < m * n; i++) {
        printf("%d", flatArr[i]);
        if (i < m * n - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

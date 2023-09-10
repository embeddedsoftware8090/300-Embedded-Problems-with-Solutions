#include <stdio.h>

// Function to search for an element in a sorted matrix
int searchInSortedMatrix(int matrix[][3], int rows, int cols, int target, int *rowIndex, int *colIndex) {
    int row = 0;           // Start from the top row
    int col = cols - 1;    // Start from the rightmost column
    
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            *rowIndex = row;
            *colIndex = col;
            return 1;  // Element found
        } else if (matrix[row][col] > target) {
            col--;      // Move left in the current row
        } else {
            row++;      // Move down to the next row
        }
    }
    
    return 0;  // Element not found
}

int main() {
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    int target = 5;
    int rowIndex, colIndex;

    if (searchInSortedMatrix(matrix, rows, cols, target, &rowIndex, &colIndex)) {
        printf("Element %d found at position (%d, %d) in the matrix.\n", target, rowIndex, colIndex);
    } else {
        printf("Element %d not found in the matrix.\n", target);
    }

    return 0;
}

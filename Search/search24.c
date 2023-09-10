#include <stdio.h>

void findRepeatingAndMissing(int arr[], int size, int *repeating, int *missing) {
    int XOR = 0;
    
    // XOR all elements in the array and all numbers from 1 to n
    for (int i = 0; i < size; i++) {
        XOR ^= arr[i];
        XOR ^= (i + 1);
    }
    
    // Find the rightmost set bit in XOR
    int rightmostSetBit = XOR & -XOR;
    
    int num1 = 0, num2 = 0;
    
    // Divide the numbers into two groups based on the rightmost set bit
    for (int i = 0; i < size; i++) {
        if (arr[i] & rightmostSetBit) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
        
        int j = i + 1;
        if (j & rightmostSetBit) {
            num1 ^= j;
        } else {
            num2 ^= j;
        }
    }
    
    // Check which number is missing by comparing with the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == num1) {
            *repeating = num1;
            *missing = num2;
            return;
        }
        if (arr[i] == num2) {
            *repeating = num2;
            *missing = num1;
            return;
        }
    }
}

int main() {
    int arr[] = {3, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int repeating, missing;
    findRepeatingAndMissing(arr, size, &repeating, &missing);
    
    printf("I/P: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]; O/P: Repeating = %d, Missing = %d\n", repeating, missing);
    
    return 0;
}

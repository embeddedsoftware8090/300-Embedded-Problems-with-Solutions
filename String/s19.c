#include <stdio.h>
#include <string.h>

// Function to count substrings with equal 0s and 1s
int countEqualSubstrings(const char *str) {
    int len = strlen(str);
    int count = 0; // Initialize the count of equal substrings
    int sum = 0;   // Initialize the prefix sum

    // Create an array to store the count of 0s and 1s encountered
    int countArray[len + 1];
    memset(countArray, 0, sizeof(countArray)); // Initialize to 0

    // Traverse the binary string
    for (int i = 0; i < len; i++) {
        // Convert '0' to -1 and '1' to 1
        int val = (str[i] == '0') ? -1 : 1;
        sum += val; // Update the prefix sum

        // If the prefix sum is 0, it means there are an equal number of 0s and 1s from the start
        if (sum == 0) {
            count++;
        }

        // If we have seen this prefix sum before, it means there are equal 0s and 1s in between
        count += countArray[sum + len];
        countArray[sum + len]++; // Increment the count of this prefix sum
    }

    return count;
}

int main() {
    const char *input_str = "0101";
    int count = countEqualSubstrings(input_str);

    printf("Number of substrings with equal 0s and 1s: %d\n", count);

    return 0;
}

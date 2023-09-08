#include <stdio.h>
#include <string.h>

// Function to find the first non-repeated character in a string
char find_first_non_repeating_character(char *str) {
  // Declare a fixed-size array to count the occurrences of each character
  int char_count[256] = {0};

  // Declare two pointers to the beginning and end of the string
  char *p1 = str;
  char *p2 = str + strlen(str);

  // Iterate over the string
  while (p1 < p2) {
    // Increment the count of the current character
    char_count[*p1]++;
    p1++;
  }

  // Declare a pointer to the first non-repeated character
  char *first_non_repeated_character = str;

  // Iterate over the string again
  p1 = str;
  while (p1 < p2) {
    // If the count of the current character is 1, then it is non-repeated
    if (char_count[*p1] == 1) {
      // Update the pointer to the first non-repeated character
      first_non_repeated_character = p1;
      break;
    }
    p1++;
  }

  // Return the first non-repeated character
  return *first_non_repeated_character;
}

// Driver program
int main() {
  // Declare the string
  char str[] = "swiss";

  // Find the first non-repeated character in the string
  char first_non_repeated_character = find_first_non_repeating_character(str);

  // Print the result
  printf("The first non-repeated character in the string is '%c'\n", first_non_repeated_character);

  return 0;
}

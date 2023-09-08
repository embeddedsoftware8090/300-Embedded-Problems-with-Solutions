#include <stdio.h>

// Custom memcpy function
void* customMemcpy(void* dest, const void* src, size_t n) {
    char* charDest = (char*)dest;
    const char* charSrc = (const char*)src;
    
    // Copy each byte from source to destination
    for (size_t i = 0; i < n; i++) {
        charDest[i] = charSrc[i];
    }
    
    return dest;
}

int main() {
    // Source string
    const char* source = "hello";
    
    // Destination buffer
    char destination[10]; // Make sure it's large enough to hold the data
    
    // Copy the data from source to destination using customMemcpy
    customMemcpy(destination, source, 5); // Copy 5 characters
    
    // Null-terminate the destination string (optional)
    destination[5] = '\0';
    
    // Print the result
    printf("Destination: %s\n", destination); // Should print "hello"
    
    return 0;
}

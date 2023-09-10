#include <stdio.h>

// Define a structure for error information
struct ErrorInfo {
    int code;
    const char *description;
};

int main() {
    // Initialize an error structure
    struct ErrorInfo error;
    error.code = 500;
    error.description = "Internal Server Error";

    // Access the error information
    int code = error.code;
    const char *description = error.description;

    printf("I/P: Code: %d; O/P: Description: \"%s\"\n", code, description);

    return 0;
}

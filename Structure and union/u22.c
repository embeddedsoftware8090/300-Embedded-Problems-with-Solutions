#include <stdio.h>
#include <string.h> // Include the string.h header for strcpy

// Define an enum to represent file types
enum FileType {
    Document,
    Image,
    Audio,
    Video,
    Other
};

// Define a structure for date (as used in Problem 2)
struct Date {
    int year;
    int month;
    int day;
};

// Define a structure to simulate file attributes
struct FileAttributes {
    char name[256]; // Assuming a maximum name length of 255 characters
    enum FileType type;
    size_t size; // Using size_t for file size
    struct Date creationDate; // Using the previously defined Date structure
};

int main() {
    // Create a FileAttributes structure
    struct FileAttributes file;

    // Fill in the file attributes
    strcpy(file.name, "document.txt");
    file.type = Document;
    file.size = 1024;
    file.creationDate.year = 2023;
    file.creationDate.month = 8;
    file.creationDate.day = 29;

    // Print the file attributes
    printf("I/P: Name: \"%s\", Type: %d, Size: %lu bytes, Creation Date: %d-%02d-%02d\n",
           file.name, file.type, file.size, file.creationDate.year,
           file.creationDate.month, file.creationDate.day);

    // Optionally, you can map the enum values to type names
    const char* fileTypeNames[] = {
        "Document", "Image", "Audio", "Video", "Other"
    };

    // Access the file type using the enum and print it
    printf("O/P: File: \"%s\", Type: %s, Size: %lu bytes, Created on: %d-%02d-%02d\n",
           file.name, fileTypeNames[file.type], file.size,
           file.creationDate.year, file.creationDate.month, file.creationDate.day);

    return 0;
}

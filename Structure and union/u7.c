#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the book structure
struct Book {
    char title[100];
    char author[100];
    int year;
};

// Initialize an array of structures to store book information
struct Book library[MAX_BOOKS];

// Track the current number of books in the library
int numBooks = 0;

// Function to add a new book to the library
void addBook(const char title[], const char author[], int year) {
    if (numBooks < MAX_BOOKS) {
        strcpy(library[numBooks].title, title);
        strcpy(library[numBooks].author, author);
        library[numBooks].year = year;
        numBooks++;
        printf("Book added successfully.\n");
    } else {
        printf("The library is full. Cannot add more books.\n");
    }
}

// Function to search for a book by title
void searchByTitle(const char keyword[]) {
    int found = 0;
    printf("Matching books:\n");

    for (int i = 0; i < numBooks; i++) {
        if (strstr(library[i].title, keyword) != NULL) {
            printf("Title: %s\nAuthor: %s\nYear: %d\n\n", library[i].title, library[i].author, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching books found.\n");
    }
}

int main() {
    // Add some sample books
    addBook("To Kill a Mockingbird", "Harper Lee", 1960);
    addBook("1984", "George Orwell", 1949);
    addBook("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    addBook("The Catcher in the Rye", "J.D. Salinger", 1951);

    // Search for books by title
    searchByTitle("Mockingbird");
    searchByTitle("1984");
    searchByTitle("Catcher");

    return 0;
}

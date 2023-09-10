#include <stdio.h>
#include <string.h>

// Define a structure to represent a book
struct Book {
    char title[100];
    char author[100];
    float price;
};

// Function to apply a discount to the book's price
void applyDiscount(struct Book *book, float discountPercentage) {
    // Calculate the discount amount
    float discountAmount = (discountPercentage / 100) * book->price;

    // Apply the discount to the price
    book->price -= discountAmount;
}

int main() {
    // Create a book and initialize its data
    struct Book myBook;
    strcpy(myBook.title, "Pride and Prejudice");
    strcpy(myBook.author, "Austen");
    myBook.price = 30.0; // Initial price in dollars

    // Apply a 15% discount to the book's price
    float discountPercentage = 15.0;
    applyDiscount(&myBook, discountPercentage);

    // Print the new price
    printf("Title: %s\n", myBook.title);
    printf("Author: %s\n", myBook.author);
    printf("New Price: $%.2f\n", myBook.price);

    return 0;
}

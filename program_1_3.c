#include <stdio.h>
#include <string.h> // Required for strcpy

// Define the Book structure
struct Book {
    int book_id;
    char title[100];
    char author[50];
    float price;
};

// Function to print book details, taking a Book structure as an argument
void printBookDetails(struct Book b) {
    printf("Book ID: %d\n", b.book_id);
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Price: %.2f\n", b.price);
}

int main() {
    // Declare a Book structure variable
    struct Book book1;

    // Initialize the book details
    book1.book_id = 101;
    strcpy(book1.title, "The C Programming Language");
    strcpy(book1.author, "Dennis Ritchie");
    book1.price = 35.50;

    // Call the function to print book details, passing book1 as an argument
    printf("Details of Book 1:\n");
    printBookDetails(book1);

    // You can create another book and print its details
    struct Book book2;
    book2.book_id = 102;
    strcpy(book2.title, "Clean Code");
    strcpy(book2.author, "Robert C. Martin");
    book2.price = 49.99;

    printf("\nDetails of Book 2:\n");
    printBookDetails(book2);

    return 0;
}
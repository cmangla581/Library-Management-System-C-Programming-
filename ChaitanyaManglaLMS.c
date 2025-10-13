// Developing a Library management System 
// Chaitanya Mangla

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a book
struct Books {
    int id;
    char title[100];
    char author[100];
    int quantity;
    struct Books *next;
};

// Function Prototypes
void addBook(struct Books **head);
void displayBooks(struct Books *head);
void searchBooks(struct Books *head, int id);

int main() {
    struct Books *Library = NULL;
    int choice;

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&Library);
                break;

            case 2:
                displayBooks(Library);
                break;

            case 3: {
                int id;
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBooks(Library, id);
                break;
            }

            case 4:
                printf("Exiting...\nGoodbye");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    struct Books *current = Library;
    while (current != NULL) {
        struct Books *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

// Function to add a new book
void addBook(struct Books **head) {
    struct Books *newNode = (struct Books *)malloc(sizeof(struct Books));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", newNode->title);  // To accept spaces

    printf("Enter Author Name: ");
    scanf(" %[^\n]", newNode->author); // To accept spaces

    printf("Enter Quantity: ");
    scanf("%d", &newNode->quantity);

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Books *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Book added successfully.\n");
}

// Function to display all books
void displayBooks(struct Books *head) {
    if (head == NULL) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    struct Books *current = head;
    while (current != NULL) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d\n",
               current->id, current->title, current->author, current->quantity);
        current = current->next;
    }
}

// Function to search for a book by ID
void searchBooks(struct Books *head, int id) {
    struct Books *current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d, Title: %s, Author: %s, Quantity: %d\n",
                   current->id, current->title, current->author, current->quantity);
            return;
        }
        current = current->next;
    }

    printf("Book with ID %d not found.\n", id);
}

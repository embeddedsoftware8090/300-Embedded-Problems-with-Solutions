#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char name[100];
    int roll;
    struct Student* next;
};

// Function to add a new student to the linked list
void addStudent(struct Student** head, const char name[], int roll) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed. Cannot add student.\n");
        return;
    }
    strcpy(newStudent->name, name);
    newStudent->roll = roll;
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    printf("Student %s, Roll: %d Added\n", name, roll);
}

// Function to print the list of students
void printStudents(struct Student* head) {
    printf("List of Students:\n");
    while (head != NULL) {
        printf("Student %s, Roll: %d\n", head->name, head->roll);
        head = head->next;
    }
}

// Function to free memory used by the linked list
void freeStudents(struct Student* head) {
    while (head != NULL) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Student* studentList = NULL; // Head of the linked list

    // Add some students
    addStudent(&studentList, "Mia", 110);
    addStudent(&studentList, "John", 111);
    addStudent(&studentList, "Alice", 112);

    // Print the list of students
    printStudents(studentList);

    // Free memory used by the linked list
    freeStudents(studentList);

    return 0;
}

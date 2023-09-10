#include <stdio.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    int marks[5]; // Array to store marks in 5 subjects
};

// Function to calculate the average marks for an array of students
float calculateAverageMarks(struct Student students[], int numStudents) {
    float totalMarks = 0.0;

    // Iterate through the array of students and calculate the total marks
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < 5; j++) {
            totalMarks += students[i].marks[j];
        }
    }

    // Calculate the average marks
    float averageMarks = totalMarks / (numStudents * 5);
    return averageMarks;
}

int main() {
    // Define an array of students
    struct Student students[3];

    // Initialize student data
    strcpy(students[0].name, "Alex");
    students[0].rollNumber = 105;
    students[0].marks[0] = 75;
    students[0].marks[1] = 80;
    students[0].marks[2] = 88;
    students[0].marks[3] = 82;
    students[0].marks[4] = 86;

    // Add more students with data...

    int numStudents = 1; // Update with the actual number of students

    // Calculate the average marks for the array of students
    float avgMarks = calculateAverageMarks(students, numStudents);

    // Print the average marks
    printf("Average Marks: %.2f\n", avgMarks);

    return 0;
}

#include <stdio.h>

// Define a structure representing a 2D point
typedef struct {
    int x;
    int y;
} Point;

// Function to move a point by a specified amount using pointer arithmetic
void movePoint(Point* p, int deltaX, int deltaY) {
    // Check if the pointer is valid
    if (p != NULL) {
        // Update the x and y coordinates
        p->x += deltaX;
        p->y += deltaY;
    }
}

int main() {
    // Create a point and initialize its coordinates
    Point myPoint;
    myPoint.x = 2;
    myPoint.y = 3;

    // Print the initial coordinates
    printf("Initial Point: (%d, %d)\n", myPoint.x, myPoint.y);

    // Move the point by (1, -1)
    movePoint(&myPoint, 1, -1);

    // Print the new coordinates after the move
    printf("New Point: (%d, %d)\n", myPoint.x, myPoint.y);

    return 0;
}

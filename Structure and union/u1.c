#include <stdio.h>
#include <math.h>

// Define a structure to represent a 3D point
struct Point3D {
    double x;
    double y;
    double z;
};

// Function to calculate the Euclidean distance between two 3D points
double calculateDistance(struct Point3D p1, struct Point3D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    // Define two 3D points
    struct Point3D p1 = {1.0, 2.0, 3.0};
    struct Point3D p2 = {4.0, 6.0, 8.0};
    
    // Calculate the distance between the two points
    double distance = calculateDistance(p1, p2);
    
    // Print the result
    printf("Distance: %.3lf\n", distance);
    
    return 0;
}

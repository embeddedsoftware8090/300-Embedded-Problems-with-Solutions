#include <stdio.h>

// Base structure for a vehicle
struct Vehicle {
    int weight;       // Weight of the vehicle in kg
    int max_speed;    // Maximum speed of the vehicle in km/h
};

// Structure for a car, derived from Vehicle
struct Car {
    struct Vehicle base;  // Embed the Vehicle structure
    int seating_capacity; // Seating capacity of the car
};

// Structure for a truck, derived from Vehicle
struct Truck {
    struct Vehicle base; // Embed the Vehicle structure
    int max_load;       // Maximum load capacity of the truck
};

// Function to print vehicle details
void printVehicleDetails(struct Vehicle *vehicle) {
    printf("Weight: %d kg\n", vehicle->weight);
    printf("Max Speed: %d km/h\n", vehicle->max_speed);
}

int main() {
    // Create a car and set its attributes
    struct Car myCar;
    myCar.base.weight = 1500;          // Car weight
    myCar.base.max_speed = 180;        // Car maximum speed
    myCar.seating_capacity = 5;        // Car seating capacity

    // Create a truck and set its attributes
    struct Truck myTruck;
    myTruck.base.weight = 8000;        // Truck weight
    myTruck.base.max_speed = 120;      // Truck maximum speed
    myTruck.max_load = 5000;           // Truck maximum load

    // Print car and truck details
    printf("Car Details:\n");
    printVehicleDetails(&myCar.base);
    printf("Seating Capacity: %d\n", myCar.seating_capacity);

    printf("\nTruck Details:\n");
    printVehicleDetails(&myTruck.base);
    printf("Maximum Load: %d kg\n", myTruck.max_load);

    return 0;
}

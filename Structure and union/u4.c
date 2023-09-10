#include <stdio.h>
#include <string.h>

// Define a structure for an address
struct Address {
    char street[100];
    char city[50];
    char state[20];
    char zip[10];
};

// Define a structure for an employee with an embedded Address structure
struct Employee {
    char name[100];
    struct Address address;
};

// Function to display the employee's address in a coherent format
void displayAddress(struct Employee emp) {
    printf("Address: %s, %s, %s, %s\n", emp.address.street, emp.address.city, emp.address.state, emp.address.zip);
}

int main() {
    // Create an employee structure and initialize its data
    struct Employee employee;
    strcpy(employee.name, "Bob");
    strcpy(employee.address.street, "456 Maple Rd");
    strcpy(employee.address.city, "Brookfield");
    strcpy(employee.address.state, "WI");
    strcpy(employee.address.zip, "53005");

    // Display the employee's address
    displayAddress(employee);

    return 0;
}

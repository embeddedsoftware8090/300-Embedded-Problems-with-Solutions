#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Add this line to include the string.h header

// Define a structure representing a menu item
struct MenuItem {
    const char *name; // Name of the menu item
    void (*action)(); // Function pointer for the associated action
};

// Functions to be executed when menu items are selected
void option1() {
    printf("Option1 Executed\n");
}

void option2() {
    printf("Option2 Executed\n");
}

void option3() {
    printf("Option3 Executed\n");
}

int main() {
    // Create menu items and associate them with functions
    struct MenuItem menu[] = {
        {"Option1", option1},
        {"Option2", option2},
        {"Option3", option3}
    };

    // Simulate selecting a menu item (e.g., "Option2")
    const char *selectedItem = "Option2";

    // Search for the selected item and execute its associated function
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        if (strcmp(selectedItem, menu[i].name) == 0) {
            menu[i].action();
            break;
        }
    }

    return 0;
}

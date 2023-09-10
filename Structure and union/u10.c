#include <stdio.h>

// Define a structure with bit fields
struct DeviceSettings {
    unsigned int setting1 : 1; // Bit 0
    unsigned int setting2 : 1; // Bit 1
    unsigned int setting3 : 1; // Bit 2
    unsigned int setting4 : 1; // Bit 3
    // Add more settings as needed
};

int main() {
    // Create an instance of the structure
    struct DeviceSettings settings;

    // Initialize the settings
    settings.setting1 = 1; // ON
    settings.setting2 = 0; // OFF
    settings.setting3 = 0; // OFF
    settings.setting4 = 1; // ON

    // Check and print the settings
    printf("I/P: Config: %d%d%d%d\n", settings.setting4, settings.setting3, settings.setting2, settings.setting1);
    if (settings.setting1)
        printf("O/P: Setting 1: ON\n");
    if (settings.setting2)
        printf("O/P: Setting 2: ON\n");
    if (settings.setting3)
        printf("O/P: Setting 3: ON\n");
    if (settings.setting4)
        printf("O/P: Setting 4: ON\n");

    return 0;
}

#include <stdio.h>

// Enumeration to represent the color type
enum ColorType {
    RGB,
    CMYK
};

// Define a union to hold RGB and CMYK color representations
union ColorData {
    struct {
        int red;
        int green;
        int blue;
    } rgb;

    struct {
        float cyan;
        float magenta;
        float yellow;
        float key;
    } cmyk;
};

// Define the main structure to represent a color
struct Color {
    enum ColorType type;
    union ColorData data;
};

// Function to print the color based on its type
void printColor(struct Color color) {
    switch (color.type) {
        case RGB:
            printf("RGB Color: [%d, %d, %d]\n", color.data.rgb.red, color.data.rgb.green, color.data.rgb.blue);
            break;
        case CMYK:
            printf("CMYK Color: [%.2f, %.2f, %.2f, %.2f]\n", color.data.cmyk.cyan, color.data.cmyk.magenta, color.data.cmyk.yellow, color.data.cmyk.key);
            break;
        default:
            printf("Invalid color type\n");
    }
}

int main() {
    struct Color color;

    // Store an RGB color
    color.type = RGB;
    color.data.rgb.red = 255;
    color.data.rgb.green = 0;
    color.data.rgb.blue = 128;
    printColor(color);

    // Store a CMYK color
    color.type = CMYK;
    color.data.cmyk.cyan = 0.2;
    color.data.cmyk.magenta = 0.8;
    color.data.cmyk.yellow = 0.0;
    color.data.cmyk.key = 0.0;
    printColor(color);

    return 0;
}

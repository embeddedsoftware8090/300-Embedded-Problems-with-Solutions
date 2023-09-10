#include <stdio.h>

// Enumeration to represent the data type
enum DataType {
    INTEGER,
    FLOAT,
    CHARACTER
};

// Define a union to hold different types of data
union DataUnion {
    int intArray[5];
    float floatArray[5];
    char charArray[5];
};

// Define the main structure to store data with a data type identifier
struct DataContainer {
    enum DataType dataType;
    union DataUnion data;
};

// Function to print the array based on data type
void printArray(struct DataContainer container) {
    switch (container.dataType) {
        case INTEGER:
            printf("Array of Integers: [");
            for (int i = 0; i < 5; i++) {
                printf("%d", container.data.intArray[i]);
                if (i < 4) printf(", ");
            }
            printf("]\n");
            break;
        case FLOAT:
            printf("Array of Floats: [");
            for (int i = 0; i < 5; i++) {
                printf("%.2f", container.data.floatArray[i]);
                if (i < 4) printf(", ");
            }
            printf("]\n");
            break;
        case CHARACTER:
            printf("Array of Characters: [");
            for (int i = 0; i < 5; i++) {
                printf("'%c'", container.data.charArray[i]);
                if (i < 4) printf(", ");
            }
            printf("]\n");
            break;
        default:
            printf("Invalid data type\n");
    }
}

int main() {
    struct DataContainer dataContainer;

    // Store an array of integers
    dataContainer.dataType = INTEGER;
    for (int i = 0; i < 5; i++) {
        dataContainer.data.intArray[i] = i + 1;
    }
    printArray(dataContainer);

    // Store an array of floats
    dataContainer.dataType = FLOAT;
    for (int i = 0; i < 5; i++) {
        dataContainer.data.floatArray[i] = (i + 1) * 1.5;
    }
    printArray(dataContainer);

    // Store an array of characters
    dataContainer.dataType = CHARACTER;
    for (int i = 0; i < 5; i++) {
        dataContainer.data.charArray[i] = 'A' + i;
    }
    printArray(dataContainer);

    return 0;
}

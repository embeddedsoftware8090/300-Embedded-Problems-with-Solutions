#include <stdio.h>
#include <stdint.h> // Include the stdint.h header for fixed-size integer types

// Define a union for a 32-bit value that can be accessed as 16-bit or 8-bit values
union Value32 {
    uint32_t full32;       // 32-bit value
    struct {
        uint16_t high16;   // Upper 16 bits
        uint16_t low16;    // Lower 16 bits
    } split16;
    struct {
        uint8_t byte1;     // Byte 1 (Most Significant Byte)
        uint8_t byte2;     // Byte 2
        uint8_t byte3;     // Byte 3
        uint8_t byte4;     // Byte 4 (Least Significant Byte)
    } split8;
};

int main() {
    union Value32 val;
    val.full32 = 0xABCD1234;

    printf("32-bit value: 0x%08X\n", val.full32);
    printf("16-bit values: 0x%04X, 0x%04X\n", val.split16.high16, val.split16.low16);
    printf("8-bit values: 0x%02X, 0x%02X, 0x%02X, 0x%02X\n", val.split8.byte1, val.split8.byte2, val.split8.byte3, val.split8.byte4);

    return 0;
}

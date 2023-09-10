#include <stdio.h>

union EndianConverter {
    unsigned int intValue;
    unsigned char byteArray[4];
};

int main() {
    union EndianConverter converter;

    // Input integer in big-endian format (0xAABBCCDD)
    converter.byteArray[0] = 0xAA;
    converter.byteArray[1] = 0xBB;
    converter.byteArray[2] = 0xCC;
    converter.byteArray[3] = 0xDD;

    // Convert to little-endian format
    unsigned int littleEndianValue =
        (converter.byteArray[3] << 24) |
        (converter.byteArray[2] << 16) |
        (converter.byteArray[1] << 8) |
        (converter.byteArray[0]);

    printf("I/P: Int: 0xAABBCCDD; O/P: Converted: 0x%08X\n", littleEndianValue);

    return 0;
}

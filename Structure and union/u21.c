#include <stdio.h>
#include <stdint.h>
#include <string.h> // Include the string.h header for strcpy

// Define a union to hold an IP address
union IPAddress {
    char ipString[16]; // Assuming IPv4 address as a string (e.g., "192.168.1.1")
    struct {
        uint8_t octet1;
        uint8_t octet2;
        uint8_t octet3;
        uint8_t octet4;
    } octets; // IPv4 address as four separate bytes
};

int main() {
    // Initialize the union with an IP address
    union IPAddress ip;
    strcpy(ip.ipString, "10.0.2.15");

    // Access the IP address as a string
    printf("I/P: IP String: \"%s\"; ", ip.ipString);

    // Access the IP address as four separate bytes
    printf("O/P: Octets: [%d, %d, %d, %d]\n",
           ip.octets.octet1, ip.octets.octet2, ip.octets.octet3, ip.octets.octet4);

    return 0;
}

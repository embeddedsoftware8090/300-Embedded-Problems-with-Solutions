#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a union to hold IP address
union IPAddress {
    char ipString[16]; // To store IP as a string (e.g., "10.0.0.1")
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } ipBytes; // To store IP as four separate bytes
};

// Function to convert IP string to bytes
void stringToBytes(const char *ipString, union IPAddress *ip) {
    sscanf(ipString, "%hhu.%hhu.%hhu.%hhu",
           &ip->ipBytes.byte1, &ip->ipBytes.byte2, &ip->ipBytes.byte3, &ip->ipBytes.byte4);
}

// Function to convert IP bytes to string
void bytesToString(const union IPAddress *ip, char *outputString) {
    snprintf(outputString, 16, "%d.%d.%d.%d",
             ip->ipBytes.byte1, ip->ipBytes.byte2, ip->ipBytes.byte3, ip->ipBytes.byte4);
}

int main() {
    // Create an IPAddress union
    union IPAddress ip;

    // Initialize it with an IP string
    const char *inputIPString = "10.0.0.1";
    strcpy(ip.ipString, inputIPString);

    // Convert IP string to bytes
    stringToBytes(inputIPString, &ip);

    // Convert IP bytes back to string
    char outputString[16];
    bytesToString(&ip, outputString);

    // Print the results
    printf("I/P: String: \"%s\"\n", inputIPString);
    printf("O/P: Bytes: %d, %d, %d, %d\n",
           ip.ipBytes.byte1, ip.ipBytes.byte2, ip.ipBytes.byte3, ip.ipBytes.byte4);

    return 0;
}

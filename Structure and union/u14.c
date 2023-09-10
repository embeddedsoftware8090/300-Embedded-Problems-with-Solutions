#include <stdio.h>

// Enum to represent packet types
enum PacketType {
    DATA,
    ACK,
    NACK
};

// Structure for a network packet
struct NetworkPacket {
    enum PacketType type; // Enum to denote packet type
    // Other packet data members can be added here
};

int main() {
    // Create a network packet of type ACK
    struct NetworkPacket packet;
    packet.type = ACK;

    // Check the packet type and print a corresponding message
    switch (packet.type) {
        case DATA:
            printf("This is a DATA packet\n");
            break;
        case ACK:
            printf("This is an ACK packet\n");
            break;
        case NACK:
            printf("This is a NACK packet\n");
            break;
        default:
            printf("Unknown packet type\n");
            break;
    }

    return 0;
}

#include <stdio.h>
#include <stdint.h>

// Define a structure to represent the data packet
struct DataPacket {
    uint16_t header;
    uint8_t payload[3];
    uint16_t checksum;
};

// Function to serialize a DataPacket into a byte array
void serializeDataPacket(const struct DataPacket *packet, uint8_t *serialized) {
    serialized[0] = (uint8_t)(packet->header >> 8);  // Extract the high byte of header
    serialized[1] = (uint8_t)(packet->header);       // Extract the low byte of header
    serialized[2] = packet->payload[0];
    serialized[3] = packet->payload[1];
    serialized[4] = packet->payload[2];
    serialized[5] = (uint8_t)(packet->checksum >> 8);  // Extract the high byte of checksum
    serialized[6] = (uint8_t)(packet->checksum);       // Extract the low byte of checksum
}

// Function to deserialize a byte array into a DataPacket
void deserializeDataPacket(const uint8_t *serialized, struct DataPacket *packet) {
    packet->header = (uint16_t)(((uint16_t)serialized[0] << 8) | serialized[1]);
    packet->payload[0] = serialized[2];
    packet->payload[1] = serialized[3];
    packet->payload[2] = serialized[4];
    packet->checksum = (uint16_t)(((uint16_t)serialized[5] << 8) | serialized[6]);
}

int main() {
    struct DataPacket originalPacket = {
        .header = 0x1234,
        .payload = {0xAA, 0xBB, 0xCC},
        .checksum = 0xABCD
    };

    uint8_t serializedData[7];
    serializeDataPacket(&originalPacket, serializedData);

    printf("Serialized: [0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X]\n",
           serializedData[0], serializedData[1], serializedData[2],
           serializedData[3], serializedData[4], serializedData[5],
           serializedData[6]);

    struct DataPacket deserializedPacket;
    deserializeDataPacket(serializedData, &deserializedPacket);

    printf("Deserialized: Header: 0x%04X, Payload: [0x%02X, 0x%02X, 0x%02X], Checksum: 0x%04X\n",
           deserializedPacket.header, deserializedPacket.payload[0],
           deserializedPacket.payload[1], deserializedPacket.payload[2],
           deserializedPacket.checksum);

    return 0;
}

#include "PacketReader.h"

using namespace std;
#include <iostream>
PacketReader::PacketReader(const string& fileName) : fileReader(fileName) {}

vector<Packet*> PacketReader::readPackets() {
    vector<Packet*> packets;
    while (true) {
        string line = fileReader.readNextLine();
        if (line.empty()) {
            break; // End of file
        }

        // Parse the line into a Packet
        Packet* packet = packetParser.parsePacket(line);

        if (packet != nullptr) {
            packets.push_back(packet);
        }
    }

    return packets;
}

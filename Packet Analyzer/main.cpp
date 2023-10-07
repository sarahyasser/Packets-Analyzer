#include <iostream>
#include "PacketReader/PacketReader.h"
#include "Visitor/Visitor.h"
#include "Visitor/WriteToOutputVisitor.h"
#include "Packet/Packet.h"

using namespace std;
int main() {
    PacketReader packetReader("../input_packets.txt");

    // Call the readPackets method to read packets from the file
    vector<Packet*> packets = packetReader.readPackets();

    WriteToOutputVisitor outputVisitor("../output_packets.txt");

    for (Packet* packet : packets) {
        // write packet to output file using visitor design pattern
       packet->accept(outputVisitor);
    }

    return 0;
}

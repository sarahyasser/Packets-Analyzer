#include <iostream>
#include "PacketReader/PacketReader.h"
#include "Visitor/Visitor.h"
#include "Visitor/WriteToOutputVisitor.h"
#include "Packet/Packet.h"

using namespace std;

int main(int argc, char* argv[]) {
    PacketReader packetReader(argv[1]);

    // Call the readPackets method to read packets from the file
    vector<Packet*> packets = packetReader.readPackets();

    WriteToOutputVisitor outputVisitor(argv[2]);

    for (Packet* packet : packets) {
        // write packet to output file using visitor design pattern
       packet->accept(outputVisitor);
    }

    cout << "Packets Analyzed Successfully !" << endl;

    return 0;
}

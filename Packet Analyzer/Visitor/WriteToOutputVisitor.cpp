#include "WriteToOutputVisitor.h"
#include "../Packet/EthernetPacket.h"
#include "../Packet/EcpriPacket.h"

WriteToOutputVisitor::WriteToOutputVisitor(const std::string& fileName) {
    outputFile.open(fileName);
}

WriteToOutputVisitor::~WriteToOutputVisitor() {
    outputFile.close();
}

void WriteToOutputVisitor::visit(EthernetPacket* packet) {
    if (packet) {
        outputFile << "Ethernet Packet Type: " << packet->getType() << "\n"; //for testing
    }
}

void WriteToOutputVisitor::visit(EcpriPacket* packet) {
    if (packet) {
        outputFile << "Ecpri Packet Type: " << packet->getRtcID() << "\n"; //for testing
    }
}
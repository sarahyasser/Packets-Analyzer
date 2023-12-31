#include "WriteToOutputVisitor.h"
#include "../Packet/EthernetPacket.h"
#include "../Packet/EcpriPacket.h"

WriteToOutputVisitor::WriteToOutputVisitor(const string &fileName) {

    // Open the file in output mode and truncate it (clear its contents)
    outputFile.open(fileName, ios::out | ios::trunc);
    outputPacketCount = 0;
    packetSeparatorLine = string(SEPARATOR_LENGTH, '*');
}

WriteToOutputVisitor::~WriteToOutputVisitor() {
    outputFile.close();
}

void WriteToOutputVisitor::visit(EthernetPacket *packet) {
    if (packet) {
        string analyzedEthernetPacket = packet->getPacketString()
                + "\nCRC: " + packet->getCyclicRedundancyCheck()
                + "\nDestination Address: " + packet->getDestinationAddress()
                + "\nSource Address: " + packet->getSourceAddress()
                + "\nType: " + packet->getType();

        writeToFile(analyzedEthernetPacket);
    }
}

void WriteToOutputVisitor::visit(EcpriPacket *packet) {

    if (packet) {
        string analyzedEcpriPacket = packet->getPacketString()
                + "\nCRC: " + packet->getCyclicRedundancyCheck()
                + "\nConcatenation Indicator: " + packet->getConcatenationIndicator()
                + "\nDestination Address: " + packet->getDestinationAddress()
                + "\nMessage Type: " + packet->getMessageType()
                + "\nPayload Size: " + packet->getPayloadSize()
                + "\nProtocol Version: " + packet->getProtocolVersion()
                + "\nRTC ID: " + packet->getRtcID()
                + "\nSequence ID: " + packet->getSequenceID()
                + "\nSource Address: " + packet->getSourceAddress()
                + "\nType: " + packet->getType()
                + "\n";

        writeToFile(analyzedEcpriPacket);
    }

}

void WriteToOutputVisitor::writeToFile(const string& analyzedPacket) {


    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // final output string format
    string outputString = "Packet # " + to_string(outputPacketCount++) + ":"
            + "\n" + analyzedPacket
            + "\n" + packetSeparatorLine
            + "\n\n";

    outputFile << outputString;
}
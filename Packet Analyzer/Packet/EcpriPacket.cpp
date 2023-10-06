#include "EcpriPacket.h"
#include "../Visitor/Visitor.h"

using namespace std;

EcpriPacket::EcpriPacket(string& packetString, string& crc, string& destinationAddress, string& sourceAddress,
                         string& type, int concatenationIndicator, int payloadSize, int protocolVersion,
                         string& rtcID, string& sequenceID)
        : Packet(packetString,crc, destinationAddress, sourceAddress, type),
          concatenationIndicator(concatenationIndicator),
          payloadSize(payloadSize),
          protocolVersion(protocolVersion),
          rtcID(rtcID),
          sequenceID(sequenceID) {
}

void EcpriPacket::accept(Visitor& visitor) {
    visitor.visit(this); // Call the appropriate visit method in the visitor
}

// Setter and getter implementations
int EcpriPacket::getConcatenationIndicator() const {
    return concatenationIndicator;
}

void EcpriPacket::setConcatenationIndicator(int concatenationIndicator) {
    this->concatenationIndicator = concatenationIndicator;
}

int EcpriPacket::getPayloadSize() const {
    return payloadSize;
}

void EcpriPacket::setPayloadSize(int payloadSize) {
    this->payloadSize = payloadSize;
}

int EcpriPacket::getProtocolVersion() const {
    return protocolVersion;
}

void EcpriPacket::setProtocolVersion(int protocolVersion) {
    this->protocolVersion = protocolVersion;
}

const string& EcpriPacket::getRtcID() const {
    return rtcID;
}

void EcpriPacket::setRtcID(const string& rtcID) {
    this->rtcID = rtcID;
}

const string& EcpriPacket::getSequenceID() const {
    return sequenceID;
}

void EcpriPacket::setSequenceID(const string& sequenceID) {
    this->sequenceID = sequenceID;
}
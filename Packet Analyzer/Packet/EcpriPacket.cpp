#include "EcpriPacket.h"
#include "../Visitor/Visitor.h"

using namespace std;

EcpriPacket::EcpriPacket(string& packetString, string& crc, string& destinationAddress, string& sourceAddress,
                         string& type, string& concatenationIndicator, string& payloadSize, string& protocolVersion,
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
const string& EcpriPacket::getConcatenationIndicator() const {
    return concatenationIndicator;
}

void EcpriPacket::setConcatenationIndicator(const string& concatenationIndicator) {
    this->concatenationIndicator = concatenationIndicator;
}

const string& EcpriPacket::getPayloadSize() const {
    return payloadSize;
}

void EcpriPacket::setPayloadSize(const string& payloadSize) {
    this->payloadSize = payloadSize;
}

const string& EcpriPacket::getProtocolVersion() const {
    return protocolVersion;
}

void EcpriPacket::setProtocolVersion(const string& protocolVersion) {
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
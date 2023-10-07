#include "EcpriPacket.h"
#include "../Visitor/Visitor.h"

using namespace std;

EcpriPacket::EcpriPacket(string& packetString, string& crc, string& destinationAddress, string& sourceAddress,
                         string& type, string& concatenationIndicator, string& payloadSize, string& protocolVersion,
                         string& rtcID, string& sequenceID, string& messageType)
        : Packet(packetString,crc, destinationAddress, sourceAddress, type),
          concatenationIndicator(concatenationIndicator),
          payloadSize(payloadSize),
          protocolVersion(protocolVersion),
          rtcID(rtcID),
          sequenceID(sequenceID),
          messageType(messageType){
}

void EcpriPacket::accept(Visitor& visitor) {
    visitor.visit(this); // Call the appropriate visit method in the visitor
}

//getter implementations
const string& EcpriPacket::getConcatenationIndicator() const {
    return concatenationIndicator;
}

const string& EcpriPacket::getPayloadSize() const {
    return payloadSize;
}

const string& EcpriPacket::getProtocolVersion() const {
    return protocolVersion;
}

const string& EcpriPacket::getRtcID() const {
    return rtcID;
}

const string& EcpriPacket::getSequenceID() const {
    return sequenceID;
}

const string &EcpriPacket::getMessageType() const {
    return messageType;
}

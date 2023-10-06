#include "Packet.h"
#include "../Visitor/Visitor.h"

using namespace std;

Packet::Packet(const string& packetString, const string& crc, const string& destinationAddress, const string& sourceAddress, const string& type)
        :packetString(packetString), cyclicRedundancyCheck(crc), destinationAddress(destinationAddress), sourceAddress(sourceAddress), type(type) {
}

const string& Packet::getCyclicRedundancyCheck() const {
    return cyclicRedundancyCheck;
}

void Packet::setCyclicRedundancyCheck(const string& crc) {
    this->cyclicRedundancyCheck = crc;
}

const string& Packet::getDestinationAddress() const {
    return destinationAddress;
}

void Packet::setDestinationAddress(const string& destinationAddress) {
    this->destinationAddress = destinationAddress;
}

const string& Packet::getSourceAddress() const {
    return sourceAddress;
}

void Packet::setSourceAddress(const string& sourceAddress) {
    this->sourceAddress = sourceAddress;
}

const string& Packet::getType() const {
    return type;
}

void Packet::setType(const string& type) {
    this->type = type;
}

const string &Packet::getPacketString() const {
    return packetString;
}

void Packet::setPacketString(const string &packetString) {
    Packet::packetString = packetString;
}

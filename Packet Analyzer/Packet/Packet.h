#ifndef PACKETSHANDLER_PACKET_H
#define PACKETSHANDLER_PACKET_H

#include <string>

class Visitor;

using namespace std;

class Packet {
protected:
    string packetString;
    string cyclicRedundancyCheck;
    string destinationAddress;
    string sourceAddress;
    string type;

public:
    Packet(const string& packetString ,const string& cyclicRedundancyCheck, const string& destinationAddress, const string& sourceAddress, const string& type);

    const string &getPacketString() const;

    void setPacketString(const string &packetString);

    // Getter for cyclic redundancy check
    const string& getCyclicRedundancyCheck() const;

    // Setter for cyclic redundancy check
    void setCyclicRedundancyCheck(const string& crc);

    // Getter for Destination Address
    const string& getDestinationAddress() const;

    // Setter for Destination Address
    void setDestinationAddress(const string& destinationAddress);

    // Getter for Source Address
    const string& getSourceAddress() const;

    // Setter for Source Address
    void setSourceAddress(const string& sourceAddress);

    // Getter for Type
    const string& getType() const;

    // Setter for Type
    void setType(const string& type);

    virtual void accept(Visitor& visitor) = 0;
};

#endif // PACKETSHANDLER_PACKET_H

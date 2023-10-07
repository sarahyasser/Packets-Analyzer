#ifndef PACKETSHANDLER_ECPRIPACKET_H
#define PACKETSHANDLER_ECPRIPACKET_H

#include "Packet.h"
#include <string>

using namespace std;

class EcpriPacket : public Packet {
private:
    string concatenationIndicator;
    string payloadSize;
    string protocolVersion;
    string rtcID;
    string sequenceID;
    string messageType;

public:
    using Packet::Packet;

    EcpriPacket(string& packetString, string& crc, string& destinationAddress, string& sourceAddress,
                string& type, string& concatenationIndicator, string& payloadSize, string& protocolVersion,
                string& rtcID, string& sequenceID, string& messageType);

    // Setters and getters
    const string& getConcatenationIndicator() const;
    void setConcatenationIndicator(const string& concatenationIndicator);

    const string &getMessageType() const;

    const string& getPayloadSize() const;
    void setPayloadSize(const string& payloadSize);

    const string& getProtocolVersion() const;
    void setProtocolVersion(const string& protocolVersion);

    const string& getRtcID() const;
    void setRtcID(const string& rtcID);

    const string& getSequenceID() const;
    void setSequenceID(const string& sequenceID);

    virtual void accept(Visitor& visitor) override;
};

#endif // PACKETSHANDLER_ECPRIPACKET_H

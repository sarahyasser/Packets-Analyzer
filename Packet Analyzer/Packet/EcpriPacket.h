#ifndef PACKETSHANDLER_ECPRIPACKET_H
#define PACKETSHANDLER_ECPRIPACKET_H

#include "Packet.h"
#include <string>

using namespace std;

class EcpriPacket : public Packet {
private:
    int concatenationIndicator;
    int payloadSize;
    int protocolVersion;
    string rtcID;
    string sequenceID;

public:
    using Packet::Packet;

    EcpriPacket(string& packetString, string& crc, string& destinationAddress, string& sourceAddress,
                string& type, int concatenationIndicator, int payloadSize, int protocolVersion,
                string& rtcID, string& sequenceID);

    // Setters and getters
    int getConcatenationIndicator() const;
    void setConcatenationIndicator(int concatenationIndicator);

    int getPayloadSize() const;
    void setPayloadSize(int payloadSize);

    int getProtocolVersion() const;
    void setProtocolVersion(int protocolVersion);

    const string& getRtcID() const;
    void setRtcID(const string& rtcID);

    const string& getSequenceID() const;
    void setSequenceID(const string& sequenceID);

    virtual void accept(Visitor& visitor) override;
};

#endif // PACKETSHANDLER_ECPRIPACKET_H

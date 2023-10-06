#ifndef PACKETSHANDLER_ETHERNETPACKET_H
#define PACKETSHANDLER_ETHERNETPACKET_H

#include "Packet.h"

class EthernetPacket : public Packet{
public:
    using Packet::Packet;
    virtual void accept(Visitor& visitor) override;
};


#endif //PACKETSHANDLER_ETHERNETPACKET_H

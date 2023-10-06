#ifndef PACKETSHANDLER_PACKETPARSER_H
#define PACKETSHANDLER_PACKETPARSER_H

#include <string>
#include <vector>
#include "../Packet/Packet.h"

class PacketParser {
public:
    static Packet* parsePacket(const std::string& data);
    static string checkType(const std::string& data);
};

#endif // PACKETSHANDLER_PACKETPARSER_H

#ifndef PACKETSHANDLER_PACKETREADER_H
#define PACKETSHANDLER_PACKETREADER_H

#include <vector>
#include <string>
#include "FileReader.h"
#include "PacketParser.h"
#include "../Packet/Packet.h"

using namespace std;

class PacketReader {
private:
    FileReader fileReader;
    PacketParser packetParser;

public:
    PacketReader(const std::string& fileName);
    vector<Packet*> readPackets();
};

#endif // PACKETSHANDLER_PACKETREADER_H
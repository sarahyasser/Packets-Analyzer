#include "PacketParser.h"
#include "../Packet/EthernetPacket.h"
#include "../Packet/EcpriPacket.h"

using namespace std;

Packet* PacketParser::parsePacket(const string& data) {
    //get packet type
    string typeCheck = checkType(data);

    //assign common members
    string packetString = data;
    string packetCyclicRedundancyCheck = packetString.substr(packetString.length() - 8, 8);
    string packetDestinationAddress = packetString.substr(16, 12);
    string packetSourceAddress = packetString.substr(28, 12);
    string packetType = packetString.substr(40, 4);

    if (typeCheck == "AEFE") {
        // It's an ecpri packet
        string ecpriConcatenationIndicator = packetString.substr(45, 1);
        string ecpriPayloadSize = packetString.substr(48, 4);
        string ecpriProtocolVersion = packetString.substr(44, 1);
        string ecpriRtcID = (packetString.substr(52, 4));
        string ecpriSequenceID = (packetString.substr(56, 4));
        string ecpriMessageType = packetString.substr(46,2);



        // Create and return an EcpriPacket
        return new EcpriPacket(packetString, packetCyclicRedundancyCheck, packetDestinationAddress, packetSourceAddress, packetType, ecpriConcatenationIndicator, ecpriPayloadSize, ecpriProtocolVersion, ecpriRtcID, ecpriSequenceID, ecpriMessageType);
    } else {
        // Create and return an EthernetPacket
        return new EthernetPacket(packetString, packetCyclicRedundancyCheck, packetDestinationAddress, packetSourceAddress, packetType);
    }
}

string PacketParser::checkType(const string &data) {
    string check = data.substr(20 * 2, 4); // Extract the type
    return check;
}



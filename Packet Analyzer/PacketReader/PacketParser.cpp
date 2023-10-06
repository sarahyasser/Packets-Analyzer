#include "PacketParser.h"
#include "../Packet/EthernetPacket.h"
#include "../Packet/EcpriPacket.h"

using namespace std;

Packet* PacketParser::parsePacket(const string& data) {
    //get packet type
    string typeCheck = checkType(data);

    //assign common members
    string packetString =data;
    string crc = "..."; //for testing
    string destinationAddress = "..."; //for testing
    string sourceAddress = "..."; //for testing
    string type = "..."; //for testing


    if (typeCheck == "AEFE") {
        // It's an ecpri packet
        int concatenationIndicator = 1;//for testing
        int payloadSize = 1;//for testing
        int protocolVersion = 1;//for testing
        string rtcID = "...";//for testing
        string sequenceID = "...";//for testing

        // Create and return an EcpriPacket
        return new EcpriPacket(packetString,crc,destinationAddress,sourceAddress,type,concatenationIndicator,payloadSize,protocolVersion,rtcID,sequenceID);
    } else {
        // Create and return an EthernetPacket
        return new EthernetPacket(packetString,crc,destinationAddress,sourceAddress,type);
    }


}

string PacketParser::checkType(const string &data) {
    string check = data.substr(20 * 2, 4); // Extract the type
    return check;
}



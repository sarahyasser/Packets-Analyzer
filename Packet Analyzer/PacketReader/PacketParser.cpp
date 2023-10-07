#include "PacketParser.h"
#include "../Packet/EthernetPacket.h"
#include "../Packet/EcpriPacket.h"

using namespace std;

Packet* PacketParser::parsePacket(const string& data) {
    //get packet type
    string typeCheck = checkType(data);

    //assign common members
    string packetString = data;
    string Packet_Cyclic_Redundancy_Check = packetString.substr(packetString.length() - 8,8);
    string Packet_Destination_Address = packetString.substr(28,12);
    string Packet_Source_Address = packetString.substr(16,12);
    string Packet_Type = packetString.substr(40,4);



    if (typeCheck == "AEFE") {
        // It's an ecpri packet
        string e_CPRI_Concatenation_Indicator = packetString.substr(45,1);
        string e_CPRI_Payload_Size = packetString.substr(48,4);
        string e_CPRI_Protocol_Version = packetString.substr(44,1);
        string e_CPRI_RTC_ID = (packetString.substr(52,4));
        string e_CPRI_Sequence_ID = (packetString.substr(56,4));



        // Create and return an EcpriPacket
        return new EcpriPacket(packetString,Packet_Cyclic_Redundancy_Check,Packet_Destination_Address,Packet_Source_Address,Packet_Type,e_CPRI_Concatenation_Indicator,e_CPRI_Payload_Size,e_CPRI_Protocol_Version,e_CPRI_RTC_ID,e_CPRI_Sequence_ID);
    } else {
        // Create and return an EthernetPacket
        return new EthernetPacket(packetString,Packet_Cyclic_Redundancy_Check,Packet_Destination_Address,Packet_Source_Address,Packet_Type);
    }


}

string PacketParser::checkType(const string &data) {
    string check = data.substr(20 * 2, 4); // Extract the type
    return check;
}



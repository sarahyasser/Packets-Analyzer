#ifndef PACKETSHANDLER_VISITOR_H
#define PACKETSHANDLER_VISITOR_H

class EthernetPacket;
class EcpriPacket;

class Visitor {

public:
    // Visit method for EthernetPacket
    virtual void visit(EthernetPacket* packet) = 0;

    // Visit method for EcpriPacket
    virtual void visit(EcpriPacket* packet) = 0;
};


#endif //PACKETSHANDLER_VISITOR_H

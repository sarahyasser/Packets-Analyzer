#ifndef PACKETSHANDLER_WRITETOOUTPUTVISITOR_H
#define PACKETSHANDLER_WRITETOOUTPUTVISITOR_H

#include "Visitor.h"
#include <fstream>
#include <iostream>
#include <string>

#define SEPARATOR_LENGTH 230

using namespace std;

class WriteToOutputVisitor : public Visitor{
private:
    ofstream outputFile;
    string packetSeparatorLine;
    int outputPacketCount;

public:
    WriteToOutputVisitor(const std::string& fileName);
    virtual ~WriteToOutputVisitor();

    virtual void visit(EthernetPacket* packet) override;
    virtual void visit(EcpriPacket* packet) override;

    void writeToFile(const string& analyzedPacket);
};


#endif //PACKETSHANDLER_WRITETOOUTPUTVISITOR_H

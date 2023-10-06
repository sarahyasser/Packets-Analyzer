#ifndef PACKETSHANDLER_WRITETOOUTPUTVISITOR_H
#define PACKETSHANDLER_WRITETOOUTPUTVISITOR_H

#include "Visitor.h"
#include <fstream>

using namespace std;

class WriteToOutputVisitor : public Visitor{
private:
    ofstream outputFile;
public:
    WriteToOutputVisitor(const std::string& fileName);
    virtual ~WriteToOutputVisitor();

    virtual void visit(EthernetPacket* packet) override;
    virtual void visit(EcpriPacket* packet) override;
};


#endif //PACKETSHANDLER_WRITETOOUTPUTVISITOR_H

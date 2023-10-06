#include "EthernetPacket.h"
#include "../Visitor/Visitor.h"

void EthernetPacket::accept(Visitor& visitor) {
    visitor.visit(this);
}
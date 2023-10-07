cmake_minimum_required(VERSION 3.19)
project(PacketsAnalyzer)

set(CMAKE_CXX_STANDARD 14)

add_executable(PacketsHandler main.cpp Packet/Packet.cpp Packet/Packet.h Visitor/Visitor.cpp Visitor/Visitor.h Visitor/WriteToOutputVisitor.cpp Visitor/WriteToOutputVisitor.h Packet/EthernetPacket.cpp Packet/EthernetPacket.h Packet/EcpriPacket.cpp Packet/EcpriPacket.h PacketReader/PacketReader.cpp PacketReader/PacketReader.h PacketReader/FileReader.cpp PacketReader/FileReader.h PacketReader/PacketParser.cpp PacketReader/PacketParser.h)
#ifndef PACKET_HPP
#define PACKET_HPP

#include <string>
#include <Other/Int24.hpp>

class Packet
{
    char *buffer = nullptr;
    short size = 0;

public:
    Packet(char *buffer, short size);
    ~Packet();
    Packet &operator=(const Packet &packet);

    unsigned short readUInt16(short pos);
    short readInt16(short pos);
    unsigned int readUInt32(short pos);
    int readInt32(short pos);
    UInt24 readUInt24(short pos);
    Int24 readInt24(short pos);
    unsigned long long readUInt64(short pos);
    long long readInt64(short pos);
    std::string readString(short pos);

    char operator[](short pos);
    bool isMagic(short pos);

    char* getBuffer();
    short getSize();
};

#endif
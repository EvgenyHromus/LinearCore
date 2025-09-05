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
    
    unsigned short getUInt16(short pos);
    short getInt16(short pos);
    unsigned int getUInt32(short pos);
    int getInt32(short pos);
    UInt24 getUInt24(short pos);
    Int24 getInt24(short pos);
    unsigned long long getUInt64(short pos);
    long long getInt64(short pos);
    std::string getString(short pos);
    
    char operator[](short pos);
    bool isMagic(short pos);
};

#endif
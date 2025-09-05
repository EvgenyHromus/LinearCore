#include "Packet.hpp"

#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

struct uint24_t { unsigned long v:24; };
struct int24_t { long v:24; };
typedef struct uint24_t __attribute__((packed)) uint24_t;

const unsigned char magic[16] = {
    0x00, 0xFF, 0xFF, 0x00,
    0xFE, 0xFE, 0xFE, 0xFE,
    0xFD, 0xFD, 0xFD, 0xFD,
    0x12, 0x34, 0x56, 0x78};

Packet::Packet(char *buffer, short size)
{
    this->buffer = (char *)realloc(buffer, size);
}
Packet::~Packet()
{
    free(this->buffer);
}
char Packet::operator[](short pos)
{
    return buffer[pos];
}
unsigned short Packet::getUInt16(short pos)
{
    return *reinterpret_cast<unsigned short*>(buffer+pos);
}
short Packet::getInt16(short pos)
{
    return *reinterpret_cast<short*>(buffer+pos);
}
UInt24 Packet::getUInt24(short pos)
{
    return *reinterpret_cast<UInt24*>(buffer+pos);
}
Int24 Packet::getInt24(short pos)
{
    return *reinterpret_cast<Int24*>(buffer+pos);
}
unsigned int Packet::getUInt32(short pos)
{
    return *reinterpret_cast<unsigned int*>(buffer+pos);
}
int Packet::getInt32(short pos)
{
    return *reinterpret_cast<int*>(buffer+pos);
}
long long Packet::getInt64(short pos)
{
    return *reinterpret_cast<long long*>(buffer+pos);
}
unsigned long long Packet::getUInt64(short pos)
{
    return *reinterpret_cast<unsigned long long*>(buffer+pos);
}
bool Packet::isMagic(short pos)
{
    return memcmp(buffer + pos, magic, 16) == 0;
}
string Packet::getString(short pos)
{
    short stringSize = getUInt16(pos);
    return string(buffer + pos + 2, stringSize);
}
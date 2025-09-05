#include "Packet.hpp"

#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

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
Packet& Packet::operator=(const Packet &packet) {
    Packet newPacket(packet.buffer,packet.size);
};
char Packet::operator[](short pos)
{
    return buffer[pos];
}
unsigned short Packet::readUInt16(short pos)
{
    return *reinterpret_cast<unsigned short *>(buffer + pos);
}
short Packet::readInt16(short pos)
{
    return *reinterpret_cast<short *>(buffer + pos);
}
UInt24 Packet::readUInt24(short pos)
{
    return *reinterpret_cast<UInt24 *>(buffer + pos);
}
Int24 Packet::readInt24(short pos)
{
    return *reinterpret_cast<Int24 *>(buffer + pos);
}
unsigned int Packet::readUInt32(short pos)
{
    return *reinterpret_cast<unsigned int *>(buffer + pos);
}
int Packet::readInt32(short pos)
{
    return *reinterpret_cast<int *>(buffer + pos);
}
long long Packet::readInt64(short pos)
{
    return *reinterpret_cast<long long *>(buffer + pos);
}
unsigned long long Packet::readUInt64(short pos)
{
    return *reinterpret_cast<unsigned long long *>(buffer + pos);
}
bool Packet::isMagic(short pos)
{
    return memcmp(buffer + pos, magic, 16) == 0;
}
string Packet::readString(short pos)
{
    short stringSize = readUInt16(pos);
    return string(buffer + pos + 2, stringSize);
}
char *Packet::getBuffer()
{
    return this->buffer;
}
short Packet::getSize()
{
    return this->size;
}
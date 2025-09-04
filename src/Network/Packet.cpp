#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

const char magic[16] = {
    0x00, 0xFF, 0xFF, 0x00,
    0xFE, 0xFE, 0xFE, 0xFE,
    0xFD, 0xFD, 0xFD, 0xFD,
    0x12, 0x34, 0x56, 0x78};

class Packet
{
    char *buffer = nullptr;
    short size = 0;

public:
    Packet(char *buffer, short size)
    {
        this->buffer = (char *)realloc(buffer, size);
    }
    ~Packet()
    {
        free(this->buffer);
    }
    char getByte(short pos)
    {
        return buffer[pos];
    }
    unsigned short getUInt16(short pos)
    {
        return reinterpret_cast<unsigned short>((void *)buffer[pos]);
    }
    short getInt16(short pos)
    {
        return reinterpret_cast<short>((void *)buffer[pos]);
    }
    unsigned int getUInt32(short pos)
    {
        return reinterpret_cast<unsigned int>((void *)buffer[pos]);
    }
    int getInt32(short pos)
    {
        return reinterpret_cast<int>((void *)buffer[pos]);
    }
    long long getInt64(short pos)
    {
        return reinterpret_cast<long long>((void *)buffer[pos]);
    }
    unsigned long long getUInt64(short pos)
    {
        return reinterpret_cast<unsigned long long>((void *)buffer[pos]);
    }
    bool isMagic(short pos)
    {
        return memcmp(buffer + pos, magic, 16) == 0;
    }
    string getString(short pos)
    {
        short stringSize = getUInt16(pos);
        return string(buffer + pos + 2, stringSize);
    }
};
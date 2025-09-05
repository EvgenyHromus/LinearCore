#include <Network/Packet.cpp>
#include <vector>

struct uint24_t { unsigned long v:24; };
typedef struct uint24_t __attribute__((packed)) uint24_t;

using std::vector;

class FrameSetPacket
{
    Packet packet;

    bool doReliable;
    bool doSequenced;
    bool doOrdered;
    bool doFragmented;

    void readPacketData()
    { 
    }

public:
    FrameSetPacket(char *buffer, short size) : packet(Packet{buffer, size})
    {
    }
    FrameSetPacket(Packet packet) : packet(packet)
    {
    }
    Packet getPacket()
    {
        return this->packet;
    }
    bool isReliable()
    {
        return doReliable;
    }
    bool isSequenced()
    {
        return doSequenced;
    }
    bool isOrdered()
    {
        return doOrdered;
    }
    bool isFragmented()
    {
        return doFragmented;
    }
};
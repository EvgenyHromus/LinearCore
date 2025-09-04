#include <Network/packet.cpp>

class FrameSetPacket : public Packet
{
    FrameSetPacket(char *buffer, short size): Packet(buffer, size) {
        
    }
};
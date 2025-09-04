#include <Network/Packet.cpp>
#include <vector>

using std::vector;

class PacketChain
{
    vector<Packet> packets;

    ~PacketChain() {}

public:
    PacketChain(Packet firstPacket)
    {
        packets.push_back(firstPacket);
    }
};
#ifndef PACKET_CHAIN_HPP
#define PACKET_CHAIN_HPP

#include <vector>
#include <Network/Packet.hpp>
#include <Network/FrameSetPacket.hpp>

class PacketChain
{
    std::vector<FrameSetPacket> chain;
    int chainID;

    PacketChain();
    PacketChain(const PacketChain &) = delete;
    PacketChain &operator=(const PacketChain &) = delete;

public:
    ~PacketChain();
    static PacketChain &getInstance();

    int getChainID()
    {
        return chainID;
    }

    bool addPacket(FrameSetPacket packet)
    {
        chain.push_back(packet);
    }

    bool checkPacket();

    Packet getFullPacket();
};

#endif
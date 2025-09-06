#ifndef RAKNET_HPP
#define RAKNET_HPP

#include <vector>
#include <Network/Packet.hpp>
#include <Network/FrameSetPacket.hpp>
#include <Network/Socket.hpp>

class Raknet {
private:
    static Raknet* pInstance;
    static bool queueEditing;

    static vector<Packet> packetQueue;
    static vector<Packet> packetQueueProcess;
    static vector<FrameSetPacket> fragmentPackets;

    Raknet();
    Raknet(const Raknet&) = delete;
    Raknet& operator=(const Raknet&) = delete;

public:
    ~Raknet();
    static Raknet& getInstance();
    
    void process();
    void pushPacket(Packet packet);
};

#endif
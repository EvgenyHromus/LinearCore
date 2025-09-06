#ifndef GAME_PACKET_HANDLER_HPP
#define GAME_PACKET_HANDLER_HPP

#include <vector>
#include <Network/Packet.hpp>
#include <Network/FrameSetPacket.hpp>
#include <Network/Socket.hpp>

class GamePacketHandler {
private:
    static GamePacketHandler* pInstance;

    static vector<Packet> gamePacketQueue;

    GamePacketHandler();
    GamePacketHandler(const GamePacketHandler&) = delete;
    GamePacketHandler& operator=(const GamePacketHandler&) = delete;

public:
    ~GamePacketHandler();
    static GamePacketHandler& getInstance();
    
    void process();
    void pushPacket(Packet packet);
};

#endif
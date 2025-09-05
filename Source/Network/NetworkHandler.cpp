#include "NetworkHandler.hpp"

#include <Network/Raknet.hpp>
#include <Network/Packet.hpp>
#include <Network/Socket.hpp>

NetworkHandler *NetworkHandler::pInstance = nullptr;

NetworkHandler::NetworkHandler()
{
}

NetworkHandler::~NetworkHandler()
{
}

NetworkHandler &NetworkHandler::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new NetworkHandler();
    }
    return *pInstance;
}

void NetworkHandler::packetWaitLoop()
{
    while (this->enabled)
    {
        short packetSize;
        Packet thisPacket(Socket::getInstance().WaitPacket(packetSize), packetSize);
        Raknet::getInstance().pushPacket(thisPacket);
    }
}
void NetworkHandler::disable()
{
    this->enabled = false;
}
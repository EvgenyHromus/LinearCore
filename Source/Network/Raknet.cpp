#include "Raknet.hpp"

Raknet *Raknet::pInstance = nullptr;

Raknet::Raknet()
{
}

Raknet::~Raknet()
{
}

Raknet &Raknet::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new Raknet();
    }
    return *pInstance;
}

void Raknet::process()
{
    while (true)
    {
        if (!queueEditing)
        {
            queueEditing = true;
            packetQueueProcess = packetQueue;
            packetQueue.clear();
            queueEditing = false;
            return;
        }
    }
}

void Raknet::pushPacket(Packet packet)
{
    while (true)
    {
        if (!queueEditing)
        {
            queueEditing = true;
            packetQueue.push_back(packet);
            queueEditing = false;
            return;
        }
    }
}
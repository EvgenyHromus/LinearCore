#include "Raknet.hpp"

#include "Json.hpp"

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
    packetQueueProcess.clear();
    fragmentPackets.clear();
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
    int packetQueueProcessSize = packetQueueProcess.size();
    for (int i = 0; i < packetQueueProcessSize; ++i) {
        if (packetQueueProcess[i][0] >= 0x80 && packetQueueProcess[i][0] <= 0x8D) {
            FrameSetPacket thisPacket = FrameSetPacket(packetQueueProcess[i]);
            json thisData = thisPacket.getData();
            short framesCount = thisData["Frames"].size();
            for (short i = 0; i < framesCount; ++i) {

            }
        }
        E
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
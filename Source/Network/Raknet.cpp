#include "Raknet.hpp"

Raknet *Raknet::instance = nullptr;

Raknet::Raknet()
{
}

Raknet::~Raknet()
{
}

Raknet &Raknet::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Raknet();
    }
    return *instance;
}
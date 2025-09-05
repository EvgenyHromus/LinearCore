#ifndef RAKNET_HPP
#define RAKNET_HPP

#include <vector>
#include <Network/Packet.hpp>
#include <Network/Socket.hpp>

class Raknet { // ИНТЕРНЕТ ДЛЯ РАКОВ!!!
private:
    static Raknet* instance;

    

    Raknet();
    Raknet(const Raknet&) = delete;
    Raknet& operator=(const Raknet&) = delete;

public:
    ~Raknet();
    static Raknet& getInstance();
};

#endif
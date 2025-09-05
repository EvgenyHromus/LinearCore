#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <winsock2.h>

class Socket
{
private:
    static Socket *instance;
    bool initialized;

    SOCKET udpSocket;

    Socket();
    Socket(const Socket &) = delete;
    Socket &operator=(const Socket &) = delete;

public:
    ~Socket();
    static Socket &getInstance();

    char *WaitPacket(short &packetSize);
    bool SendPacket(const unsigned char ip[4], short port, const char *data, int dataSize);

    bool isInitialized() const { return initialized; }
    void shutdown();
};

#endif
#include "Socket.hpp"
#include <iostream>
#include <cstring>

#define PORT 6560
#define MTU 1500

Socket *Socket::instance = nullptr;

Socket::Socket() : initialized(false), udpSocket(INVALID_SOCKET)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
        throw std::runtime_error("WSAStartup failed");
    }
    udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
        throw std::runtime_error("Socket creation failed");
        exit(2);
    }
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(udpSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind to port " << PORT << " failed: " << WSAGetLastError() << std::endl;
        closesocket(udpSocket);
        throw std::runtime_error("Bind to port failed");
    }
    initialized = true;
}

Socket::~Socket()
{
    shutdown();
}

Socket &Socket::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Socket();
    }
    return *instance;
}

char *Socket::WaitPacket(short &packetSize)
{
    if (!initialized)
    {
        throw std::runtime_error("Socket not initialized");
    }
    char *buffer = new char[MTU];
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    int bytesReceived = recvfrom(udpSocket, buffer, MTU, 0, (sockaddr *)&clientAddr, &clientAddrSize);
    if (bytesReceived == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        delete[] buffer;
        throw std::runtime_error("recvfrom failed: " + std::to_string(error));
    }
    if (bytesReceived == 0)
    {
        delete[] buffer;
        return nullptr;
    }
    char *result = new char[bytesReceived];
    memcpy(result, buffer, bytesReceived);
    delete[] buffer;
    packetSize = bytesReceived;
    return result;
}

bool Socket::SendPacket(const unsigned char ip[4], short port, const char *data, int dataSize)
{
    if (!initialized || !data || dataSize <= 0)
    {
        return false;
    }
    sockaddr_in destAddr;
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(port);
    destAddr.sin_addr.s_addr = (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | ip[3];

    int bytesSent = sendto(udpSocket, data, dataSize, 0, (sockaddr *)&destAddr, sizeof(destAddr));
    if (bytesSent == SOCKET_ERROR)
    {
        std::cerr << "Sendto failed: " << WSAGetLastError() << std::endl;
        return false;
    }
    return bytesSent == dataSize;
}

void Socket::shutdown()
{
    if (udpSocket != INVALID_SOCKET)
    {
        closesocket(udpSocket);
        udpSocket = INVALID_SOCKET;
    }
    WSACleanup();
    initialized = false;
}
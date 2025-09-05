#ifndef NETWORK_HANDLER_HPP
#define NETWORK_HANDLER_HPP

class NetworkHandler {
private:
    static NetworkHandler* pInstance;
    bool enabled = true;

    NetworkHandler();
    NetworkHandler(const NetworkHandler&) = delete;
    NetworkHandler& operator=(const NetworkHandler&) = delete;

public:
    ~NetworkHandler();
    static NetworkHandler& getInstance();

    void packetWaitLoop();
    void disable();
};

#endif
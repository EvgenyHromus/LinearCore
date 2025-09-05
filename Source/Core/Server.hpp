#ifndef SERVER_HPP
#define SERVER_HPP

class Server {
private:
    static Server* instance;
    bool initialized;

    Server();
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

public:
    ~Server();
    static Server& getInstance();
};

#endif
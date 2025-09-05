#include <thread>

using std::thread;

class Server
{
    thread *mainTickThread = nullptr;
    void mainLoop()
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    void init()
    {
        mainTickThread = new thread(mainLoop);
    }

public:
    Server() {
        init();
    }
};
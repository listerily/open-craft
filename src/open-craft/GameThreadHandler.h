#ifndef OPEN_CRAFT_GAME_THREAD_HANDLER_H
#define OPEN_CRAFT_GAME_THREAD_HANDLER_H

#include <thread>
#include <mutex>

class OpenCraftClient;
class RenderEngine;
class GameThreadHandler
{
private:
    OpenCraftClient& client;
    RenderEngine& engine;
    std::thread* ticker;
    std::mutex lock;
    [[noreturn]] void gameTick();
public:
    GameThreadHandler(OpenCraftClient&, RenderEngine&);
    ~GameThreadHandler();
    void renderTick();
    void startGameTicking();
};


#endif //OPEN_CRAFT_GAME_THREAD_HANDLER_H

#include "GameThreadHandler.h"

#include "renderer/RenderEngine.h"
#include "client/OpenCraftClient.h"

GameThreadHandler::GameThreadHandler(OpenCraftClient & client, RenderEngine & engine) : engine(engine), client(client)
{
    ticker = new std::thread(&GameThreadHandler::gameTick, this);
}

GameThreadHandler::~GameThreadHandler()
{
    delete ticker;
}

void GameThreadHandler::renderTick()
{
    lock.lock();
    engine.renderTick();
    lock.unlock();
}

[[noreturn]] void GameThreadHandler::gameTick()
{
    while(true)
    {
        lock.lock();
        client.tick();
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void GameThreadHandler::startGameTicking()
{
    ticker->detach();
}

#include "GameThreadHandler.h"

#include "renderer/RenderEngine.h"
#include "client/OpenCraftGame.h"

GameThreadHandler::GameThreadHandler(OpenCraftGame &client, RenderEngine &engine) : engine(engine), game(client)
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
    while (true)
    {
        lock.lock();
        game.tick();
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void GameThreadHandler::startGameTicking()
{
    ticker->detach();
}

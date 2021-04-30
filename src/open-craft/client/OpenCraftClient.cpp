#include "OpenCraftClient.h"

OpenCraftClient::OpenCraftClient(MainApplication & main) : main(main)
{
    world = nullptr;
    player = nullptr;
}

OpenCraftClient::~OpenCraftClient()
{
    delete world;
    delete player;
}

void OpenCraftClient::createWorld()
{

}

void OpenCraftClient::tick()
{

}

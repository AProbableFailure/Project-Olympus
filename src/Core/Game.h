#pragma once
#include <iostream>
#include "SDL2/SDL.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

    void initialize(const char * title, bool fullscreen);
    void handle_events(); // DEPRECATED
    void update(double deltaTime);
    void render();
    void clean();

    bool is_running() { return m_is_running; }

private:
    bool m_is_running = false;
};
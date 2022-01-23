#include "../include/core.hpp"

void Core::draw()
{
    player.Draw(window);
    for(Asteroid *asteroid : asteroids)
    {
        asteroid->Draw(window);
    }
}

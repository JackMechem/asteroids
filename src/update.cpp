#include "../include/core.hpp"
#include <SFML/Graphics.hpp>
#include "../include/player.hpp"

void Core::update()
{
    player.Update(dt);
    if(asteroids.size() != 0)
    {
        for(Asteroid *asteroid : asteroids)
        {
            asteroid->Update(dt, window);
        }
    }
}
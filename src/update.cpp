#include "../include/core.hpp"
#include <SFML/Graphics.hpp>

void Core::update()
{
    player.Update(dt);
}
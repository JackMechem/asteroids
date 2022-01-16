#include "../include/core.hpp"
#include <SFML/Graphics.hpp>
#include "../include/player.hpp"

void Core::update()
{
    player.Update(dt);
}
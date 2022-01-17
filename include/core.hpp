#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "player.hpp"

using namespace sf;

class Core {
private:
    // Window
    Vector2f windowRes;
    RenderWindow window; // Window instance
    const unsigned int FPS = 60; // FPS cap to check if delta time is working

    float dt; // Delta Time

    Player player; // Create an instance of the player

public:
    Core(); // Default construstor


    void update();
    void draw();

    void run();
};
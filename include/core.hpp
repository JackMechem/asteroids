#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>

#include "player.hpp"

using namespace sf;

class Core {
private:
    // Window
    Vector2f windowRes;
    RenderWindow window;
    const unsigned int FPS = 500;
    static const Time TimePerFrame;

    float dt;

    Player player;

public:
    Core(); // Default construstor

    bool inputLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    bool inputRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    bool inputUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    bool inputDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

    void input();
    void update();
    void draw();



    void run();
    
};
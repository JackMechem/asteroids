#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{

public:
    Player(std::string texturePath)
    {

        playerObject = sf::RectangleShape(sf::Vector2f(playerx, playery));

        playerTexture.loadFromFile(texturePath);
        playerObject.setTexture(&playerTexture);

    }

    void Update(float dt);

    sf::RectangleShape GetPlayerObject();

    ~Player()
    {
    }

private:
    sf::RectangleShape playerObject;

    sf::Texture playerTexture;

    float dt;

    float playerx = 60.0f;
    float playery = 100.0f;
    float playerSpeed = 200.0f;

    float playerAcc = 0.02f;
    float playerVelx = 0.0f;
    float playerVely = 0.0f;
    float maxVel = 150.0f;
    void Input();
};
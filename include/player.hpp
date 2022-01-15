#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{

public:
    Player();

    void Update(float dt);

    sf::RectangleShape GetPlayerObject();


private:


    void PlayerMovement(float dt);
    sf::RectangleShape playerObject;

    sf::Texture playerTexture;

    float dt;

    float playerx = 40.0f;
    float playery = 60.0f;
    std::string playerTextureDIR = "images/player.png";

    float playerAcc = 200.0f;
    float playerVelx = 0.0f;
    float playerVely = 0.0f;
    float maxVel = 200.0f;

    float playerAA = 500.0f;
    float playerAVx = 0.0f;
    float playerAVy = 0.0f;
    float maxAV = 100.0f;
};
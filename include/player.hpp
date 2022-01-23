#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "bullet.hpp"

class Player
{

public:
    Player();


    void Update(float dt);

    sf::RectangleShape GetPlayerObject();

    void Draw(sf::RenderWindow &Window);

private:


    void PlayerMovement(float dt);
    sf::RectangleShape playerObject;

    sf::Texture playerTexture;
    sf::Image bulletImage;

    bool isPressed;

    float dt;

    float playerx = 40.0f;
    float playery = 60.0f;
    std::string playerTextureDIR = "images/player.png";
    std::string bulletTextureDIR = "images/bullet.png";

    float playerAcc = 200.0f;
    float playerVelx = 0.0f;
    float playerVely = 0.0f;
    float maxVel = 200.0f;

    float playerAA = 500.0f;
    float playerAVx = 0.0f;
    float playerAVy = 0.0f;
    float maxAV = 100.0f;

    std::vector<Bullet*> bullets;

};

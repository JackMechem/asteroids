#include "../include/player.hpp"
#include <cmath>

#include "../include/bullet.hpp"



Player::Player()
{

    playerObject = sf::RectangleShape(sf::Vector2f(playerx, playery));

    playerTexture.loadFromFile("images/player.png");
    playerObject.setTexture(&playerTexture);
    playerObject.setOrigin(playerx / 2, playery / 2);
    playerObject.setPosition(sf::Vector2f(20.f, 20.f));
}

void Player::Update(float dt)
{
    PlayerMovement(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        Bullet bullet;
        bullet.instantiate();
    }
}


void Player::PlayerMovement(float dt)
{

    bool inputLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    bool inputRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    bool inputUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    bool inputDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

    float playerAccDT = playerAcc * dt;
    float playerAADT = playerAA * dt;

    if (inputRight)
    {
        // playerObject.setRotation(90);
        if (playerAVx < maxAV)
            playerAVx += playerAADT;
    }
    if (inputLeft)
    {
        if (playerAVx > -maxAV)
            playerAVx -= playerAADT;
    }
    if (inputDown)
    {
        // playerObject.setRotation(180);
        if (playerVely < maxVel)
            playerVely += playerAccDT;
    }
    if (inputUp)
    {
        // playerObject.setRotation(0);
        if (playerVely > -maxVel)
            playerVely -= playerAccDT;
    }

    if (inputRight == false && inputLeft == false)
    {
        if (playerAVx != 0)
        {
            if (playerAVx < 0)
            {
                playerAVx += playerAADT;
            }
            if (playerAVx > 0)
            {
                playerAVx -= playerAADT;
            }
        }
    }
    if (inputDown == false && inputUp == false)
    {
        if (playerVely != 0)
        {
            if (playerVely < 0)
            {
                playerVely += playerAccDT;
            }
            if (playerVely > 0)
            {
                playerVely -= playerAccDT;
            }
        }
    }

    float AngMovx = -playerVely * std::sin(playerObject.getRotation() * M_PI / 180);
    float AngMovy = playerVely * std::cos(playerObject.getRotation() * M_PI / 180);
    playerObject.move(AngMovx * dt, AngMovy * dt);
    playerObject.rotate(playerAVx * dt);
}

sf::RectangleShape Player::GetPlayerObject()
{
    return playerObject;
}
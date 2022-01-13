#include "../include/player.h"


void Player::Update(float dt)
{


        bool inputLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
        bool inputRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
        bool inputUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
        bool inputDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);


        if (inputRight)
        {
            // playerObject.setRotation(90);
            if (playerVelx < maxVel)
                playerVelx += playerAcc;
        }
        if (inputLeft)
        {
            // playerObject.setRotation(270);
            if (playerVelx > -maxVel)
                playerVelx -= playerAcc;
        }
        if (inputDown)
        {
            // playerObject.setRotation(180);
            if (playerVely < maxVel)
                playerVely += playerAcc;
        }
        if (inputUp)
        {
            // playerObject.setRotation(0);
            if (playerVely > -maxVel)
                playerVely -= playerAcc;
        }

        if (inputRight == false && inputLeft == false)
        {
            if (playerVelx != 0)
            {
                if (playerVelx < 0)
                {
                    playerVelx += playerAcc;
                }
                if (playerVelx > 0)
                {
                    playerVelx -= playerAcc;
                }
            }
        }
        if (inputDown == false && inputUp == false)
        {
            if (playerVely != 0)
            {
                if (playerVely < 0)
                {
                    playerVely += playerAcc;
                }
                if (playerVely > 0)
                {
                    playerVely -= playerAcc;
                }
            }
        }

        playerObject.move(playerVelx * dt, playerVely * dt);

}

sf::RectangleShape Player::GetPlayerObject()
{
    return playerObject;
}
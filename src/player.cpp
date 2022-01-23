#include "../include/player.hpp"
#include <cmath>
#include <vector>


Player::Player()
{


    playerObject = sf::RectangleShape(sf::Vector2f(playerx, playery));

    playerTexture.loadFromFile("images/player.png");
    playerObject.setTexture(&playerTexture);
    playerObject.setOrigin(playerx / 2, playery / 2);
    playerObject.setPosition(sf::Vector2f(20.f, 20.f));

    bulletImage.loadFromFile(bulletTextureDIR);

}

void Player::Update(float dt)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isPressed)
    {
        isPressed = true;
        bullets.push_back(new Bullet(playerObject.getPosition().x, playerObject.getPosition().y, 600, playerObject.getRotation(), bulletImage));
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isPressed){
        isPressed = false;
    }

    PlayerMovement(dt);

    if (bullets.size() != 0)
    {
        for (Bullet *bullet : bullets)
        {
            bullet->Update(dt);
        }
    }

    if(bullets.size() != 0)
    {
        for (int i=0; i<bullets.size(); i++)
        {
            if ((bullets[i]->GetX() > 4000 + 40) || (bullets[i]->GetX() < 0 - 40) ||
                (bullets[i]->GetY() > 4000 + 40) || (bullets[i]->GetY() < 0 - 40))
                {
                    bullets.erase(bullets.begin() +i);
                }
        }
        // std::cout<<bullets.size()<<std::endl;
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

void Player::Draw(sf::RenderWindow &Window)
{
    Window.draw(playerObject);

    if (bullets.size() != 0)
    {
        for (Bullet *bullet : bullets)
        {
            bullet->Draw(Window);
        }
    }
}
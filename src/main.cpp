#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/player.h"

int main()
{

    sf::Clock clock;
    sf::Time time;

    int windowx = 512;
    int windowy = 512;
    
    Player player("images/player.png");

    // float playerx = 60.0f;
    // float playery = 100.0f;
    // float playerSpeed = 200.0f;

    // float playerAcc = 0.02f;
    // float playerVelx = 0.0f;
    // float playerVely = 0.0f;
    // float maxVel = 150.0f;

    sf::RenderWindow window(sf::VideoMode(windowx, windowy), "Asteroids", sf::Style::Close | sf::Style::Resize);
    // sf::RectangleShape player(sf::Vector2f(playerx, playery));

    // sf::Texture playerTexture;
    // playerTexture.loadFromFile("images/player.png");
    // player.setTexture(&playerTexture);

    while (window.isOpen())
    {
        sf::Event evnt;

        float dt = clock.restart().asSeconds();

        while (window.pollEvent(evnt))
        {

            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                sf::FloatRect visibleArea(0, 0, evnt.size.width, evnt.size.height);
                window.setView(sf::View(visibleArea));
                break;
            }
        }

        player.Update(dt);

        // bool inputLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
        // bool inputRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
        // bool inputUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
        // bool inputDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);


        // if (inputRight)
        // {
        //     if (playerVelx < maxVel)
        //         playerVelx += playerAcc;
        // }
        // if (inputLeft)
        // {
        //     if (playerVelx > -maxVel)
        //         playerVelx -= playerAcc;
        // }
        // if (inputDown)
        // {
        //     if (playerVely < maxVel)
        //         playerVely += playerAcc;
        // }
        // if (inputUp)
        // {
        //     if (playerVely > -maxVel)
        //         playerVely -= playerAcc;
        // }

        // if (inputRight == false && inputLeft == false)
        // {
        //     if (playerVelx != 0)
        //     {
        //         if (playerVelx < 0)
        //         {
        //             playerVelx += playerAcc;
        //         }
        //         if (playerVelx > 0)
        //         {
        //             playerVelx -= playerAcc;
        //         }
        //     }
        // }
        // if (inputDown == false && inputUp == false)
        // {
        //     if (playerVely != 0)
        //     {
        //         if (playerVely < 0)
        //         {
        //             playerVely += playerAcc;
        //         }
        //         if (playerVely > 0)
        //         {
        //             playerVely -= playerAcc;
        //         }
        //     }
        // }

        // player.move(playerVelx * dt, playerVely * dt);

        window.clear(sf::Color(0, 0, 0));
        window.draw(player.GetPlayerObject());
        window.display();
    }

    return 0;
}
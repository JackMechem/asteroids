#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    sf::Clock clock;
    sf::Time time;

    int windowx = 512;
    int windowy = 512;

    float playerx = 60.0f;
    float playery = 100.0f;
    float playerSpeed = 200.0f;

    float playerAcc = 50.0f;
    float playerVel = 0.0f;
    float maxVel = 200.0f;

    sf::RenderWindow window(sf::VideoMode(windowx, windowy), "Asteroids", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(playerx, playery));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/player.png");
    player.setTexture(&playerTexture);

    while (window.isOpen())
    {
        sf::Event evnt;

        time = clock.restart();
        float dt = time.asSeconds();

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (playerVel < maxVel)
                playerVel += playerAcc * dt;
            player.move(-playerVel * dt, 0.0f);
        }
        else
        {
            if (playerVel > 0)
            {
                playerVel -= playerAcc * dt;
                player.move(-playerVel * dt, 0.0f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.move(0.0f, -playerSpeed * dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.move(playerSpeed * dt, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player.move(0.0f, playerSpeed * dt);
        }

        window.clear(sf::Color(0, 0, 0));
        window.draw(player);
        window.display();
    }

    return 0;
}
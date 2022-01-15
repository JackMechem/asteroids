#include "../include/core.hpp"

Core::Core()
{
    windowRes = Vector2f(800, 600);
    window.create(VideoMode(windowRes.x, windowRes.y), "Asteroids", Style::Default);
    window.setFramerateLimit(FPS);
}

void Core::run()
{

    sf::Clock clock;
    sf::Time time;



    while (window.isOpen())
    {
        sf::Event evnt;

        dt = clock.restart().asSeconds();

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

        update();


        window.clear(sf::Color(0, 0, 0));
        draw();
        window.display();
    }
}

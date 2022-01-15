#include "../include/core.hpp"



int main()
{
    Core core;
    core.run();
    return 0;
}




// int main()
// {


//     sf::Clock clock;
//     sf::Time time;

//     int windowx = 512;
//     int windowy = 512;
    
//     Player player("images/player.png");

//     sf::RenderWindow window(sf::VideoMode(windowx, windowy), "Asteroids", sf::Style::Close | sf::Style::Resize);

//     while (window.isOpen())
//     {
//         sf::Event evnt;

//         float dt = clock.restart().asSeconds();

//         while (window.pollEvent(evnt))
//         {

//             switch (evnt.type)
//             {
//             case sf::Event::Closed:
//                 window.close();
//                 break;
//             case sf::Event::Resized:
//                 sf::FloatRect visibleArea(0, 0, evnt.size.width, evnt.size.height);
//                 window.setView(sf::View(visibleArea));
//                 break;
//             }
//         }

//         player.Update(dt);

//         window.clear(sf::Color(0, 0, 0));
//         window.draw(player.GetPlayerObject());
//         window.display();
//     }

//     return 0;
// }
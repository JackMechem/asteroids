#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    std::vector<sf::CircleShape> getBullets();

    void instantiate(); 
private:
    std::vector<sf::CircleShape> bullets;

    float bulletRad = 10.0f;
};
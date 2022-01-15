#include "../include/bullet.hpp"

Bullet::Bullet()
{
}

void Bullet::instantiate()
{
    sf::CircleShape bulletObj = sf::CircleShape(10.0f);

    bulletObj.move(0.0f, 10.0f);
}
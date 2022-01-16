#include "../include/bullet.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

Bullet::Bullet(void){}

Bullet::Bullet(float x,float y,float v,float r,sf::Image image)
{
    LoadResources(x,y,v,r,image);
}

Bullet::~Bullet(void){}

void Bullet::LoadResources(float x,float y,float v,float r , sf::Image image)
{
    this->x = x;
    this->y = y;
    this->v = v;

    bulletImg.loadFromImage(image);
    bulletSpr.setTexture(bulletImg);
    bulletSpr.setScale(0.01,0.01);
    bulletSpr.setOrigin(bulletImg.getSize().x / 2,bulletImg.getSize().y / 2);
    bulletSpr.setPosition(x,y);
    bulletSpr.setRotation(r);
}

void Bullet::UnloadResources(){}

void Bullet::Update(float dt)
{
    x += (sin(bulletSpr.getRotation() * (3.14159265/180.0)) *v * dt);
    y -= (cos(bulletSpr.getRotation() * (3.14159265/180.0)) *v * dt);

    bulletSpr.setPosition(x,y);
}

void Bullet::SetX(float x)
{
    this->x = x;
}

void Bullet::SetY(float y)
{
    this->y = y;
}

void Bullet::SetRotation(float r)
{
    rotation = r;
}

float Bullet::GetX()
{
    return x;
}

float Bullet::GetY()
{
    return y;
}

void Bullet::Draw(sf::RenderWindow &Window)
{
    Window.draw(bulletSpr);
}
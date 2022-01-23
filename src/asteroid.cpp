#include "../include/asteroid.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <random>
#include <time.h>

Asteroid::Asteroid(void) {}

Asteroid::Asteroid(float v, sf::Image image)
{
	LoadResources(v, image);
}

Asteroid::~Asteroid(void) {}

void Asteroid::LoadResources(float v, sf::Image image)
{
	this->x = x;
	this->y = y;
	this->v = v;

	asteroidImg.loadFromImage(image);
	asteroidSpr.setTexture(asteroidImg);
	asteroidSpr.setScale(0.5, 0.5);
	asteroidSpr.setOrigin(asteroidImg.getSize().x / 2, asteroidImg.getSize().y / 2);
	asteroidSpr.setPosition(x, y);
}

void Asteroid::Update(float dt, sf::RenderWindow &window)
{
	if (canSpawn)
	{

		int screenSide = rand() % 3; // Random screen side, 0: left, 1: right, 2: top, 3: bottom

		switch (screenSide)
		{
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		default:
			break;
		}
	}
}

void Asteroid::SetX(float x)
{
	this->x = x;
}

void Asteroid::SetY(float y)
{
	this->y = y;
}

void Asteroid::SetRotation(float r)
{
	rotation = r;
}

float Asteroid::GetX()
{
	return x;
}

float Asteroid::GetY()
{
	return y;
}

void Asteroid::Draw(sf::RenderWindow &Window)
{
	Window.draw(asteroidSpr);
}
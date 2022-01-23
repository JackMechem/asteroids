#include <SFML/Graphics.hpp>

class Asteroid {

public:

	Asteroid();

	Asteroid(float v, sf::Image image);

	void LoadResources(float v, sf::Image image);

	void UnloadResources() { }

	void Update(float dt, sf::RenderWindow &window);

	void SetX(float x);

	void SetY(float y);

	void SetRotation(float r);

	float GetX();

	float GetY();

	float GetTest();

	void Draw(sf::RenderWindow &Window);

	~Asteroid();

private:

    float x;
    float y;
    float v;

    float rotation;

	bool canSpawn = false;

    sf::Texture asteroidImg;
    sf::Sprite asteroidSpr;

};
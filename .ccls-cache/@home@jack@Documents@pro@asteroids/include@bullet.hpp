#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet {
public:

    Bullet();

    Bullet(float x,float y,float v,float r,sf::Image image);

    void LoadResources(float x,float y,float v,float r , sf::Image image);

    void UnloadResources();

    void Update(float dt);

    void SetX(float x);

    void SetY(float y);

    void SetRotation(float r);

    float GetX();

    float GetY();

    void Draw(sf::RenderWindow &Window);

    ~Bullet();

private:

    float x;
    float y;
    float v;

    float rotation;

    sf::Texture bulletImg;
    sf::Sprite bulletSpr;

};

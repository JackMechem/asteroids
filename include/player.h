#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {

public:

    Player(){
        //default
    };

    Player(std::string imgDirectory){
        if(!playerTexture.loadFromFile(imgDirectory)){
            std::cerr << "Error\n";
        }
        playerSprite.setTexture(playerTexture);
    }

    void drawPlayer(sf::RenderWindow &window){
        window.draw(playerSprite);
    }

    void movePlayer(char direction, float moveSpeed, float dt){
        if(direction == 'u'){
            playerSprite.move(0, -moveSpeed * dt);
        } if(direction == 'd'){
            playerSprite.move(0, moveSpeed * dt);
        } if(direction == 'l'){
            playerSprite.move(moveSpeed * dt, 0.0f);
        } if(direction == 'r'){
            playerSprite.move(-moveSpeed * dt, 0);
        }



    }

private:

    sf::Texture playerTexture;
    sf::Sprite playerSprite;


    float playerx = 60.0f;
    float playery = 100.0f;
    float playerSpeed = 200.0f;

    void Input();

};
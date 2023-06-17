#include "SFML/Graphics.hpp"
#include "headers/Bar.hpp"
#include <iostream>

Bar::Bar(sf::Vector2f pos){

    this->pos = pos;
    this->width = 10;
    this->body.setOutlineThickness(1.f);
    this->body.setPosition(pos);
    this->body.setFillColor(sf::Color::White);
    this->body.setOutlineColor(sf::Color::Black);
}
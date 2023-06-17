#include "SFML/Graphics.hpp"

class Bar{

public:
    Bar(sf::Vector2f);

    int height;
    int width;
    sf::Vector2f pos;
    sf::RectangleShape body;
    
};
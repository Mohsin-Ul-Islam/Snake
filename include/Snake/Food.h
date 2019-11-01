#ifndef FOOD_H
#define FOOD_H

#include<SFML/Graphics.hpp>

class Food
{

  public:

    Food();
    Food(const int& l_size);
    void generate();
    void renderFood(sf::RenderWindow& l_window);
    sf::Vector2f getPosition() const;
    ~Food();

  private:

    void init(const int& l_size);

    int m_size;
    sf::Vector2f m_position;
    sf::Color m_color;

};

#endif

#ifndef FOOD_H
#define FOOD_H

#include "Snake.h"

class Food
{

  public:

    Food();
    Food(const int& l_size);
    void generate(const Snake& l_snake);
    void render(sf::RenderWindow& l_window);
    void setSize(const int& l_size);
    inline sf::Vector2f getPosition() const {return m_position;};
    ~Food();

  private:

    void init(const int& l_size);

    int m_size;
    sf::Vector2f m_position;
    sf::Color m_color;

};

#endif

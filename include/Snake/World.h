#ifndef WORLD_H
#define WORLD_H

#include "Snake/Snake.h"
#include "Snake/Food.h"

class World
{
  public:

    World();
    World(const int& l_size);
    ~World();
    void setEntitySize(const int& l_size);
    inline Snake& snake() {return m_snake;};
    inline Food&  food() {return m_food;};
    void render(sf::RenderWindow& l_window);


  private:

    void init(const int& l_size);

    int   m_size;
    Snake m_snake;
    Food  m_food;

    sf::RectangleShape boundaries[4];

};

#endif

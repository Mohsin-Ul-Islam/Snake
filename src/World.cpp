#include "Snake/World.h"

World::World()
{
  init(10);
}

World::World(const int& l_size)
{
  init(l_size);
}

World::~World()
{

}

void World::setEntitySize(const int& l_size)
{
  m_size = l_size;
  init(m_size);
  return;
}

void World::init(const int& l_size)
{
  m_size = l_size;
  m_snake.setSize(m_size);
  m_snake.setLivesCount(3);
  m_food.setSize(m_size);
  return;
}

void World::render(sf::RenderWindow& l_window)
{
  m_snake.render(l_window);
  m_food.render(l_window);
  return;
}

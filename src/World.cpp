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


  boundaries[0].setSize(sf::Vector2f(20,1080));
  boundaries[0].setOrigin(sf::Vector2f(0,0));
  boundaries[0].setPosition(sf::Vector2f(0,0));
  boundaries[0].setFillColor(sf::Color::Yellow);
  boundaries[1].setSize(sf::Vector2f(1920,20));
  boundaries[1].setOrigin(sf::Vector2f(0,0));
  boundaries[1].setPosition(sf::Vector2f(0,0));
  boundaries[1].setFillColor(sf::Color::Yellow);
  boundaries[2].setSize(sf::Vector2f(20,1080));
  boundaries[2].setOrigin(sf::Vector2f(0,0));
  boundaries[2].setPosition(sf::Vector2f(1900,0));
  boundaries[2].setFillColor(sf::Color::Yellow);
  boundaries[3].setSize(sf::Vector2f(1920,20));
  boundaries[3].setOrigin(sf::Vector2f(0,0));
  boundaries[3].setPosition(sf::Vector2f(0,1060));
  boundaries[3].setFillColor(sf::Color::Yellow);


  return;
}

void World::render(sf::RenderWindow& l_window)
{
  m_snake.render(l_window);
  m_food.render(l_window);
  l_window.draw(boundaries[0]);
  l_window.draw(boundaries[1]);
  l_window.draw(boundaries[2]);
  l_window.draw(boundaries[3]);
  return;
}

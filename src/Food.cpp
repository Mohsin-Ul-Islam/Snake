#include "Snake/Food.h"

Food::Food()
{
  init(10);
}

Food::Food(const int& l_size)
{
  init(l_size);
}

Food::~Food()
{

}

void Food::init(const int& l_size)
{
  srand(time(0));
  m_size = l_size;
  m_position.x =  1;
  m_position.y =  1;
  m_color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
  return;
}

void Food::generate()
{
  m_position.x = rand() % 25 + 1;
  m_position.y = rand() % 15 + 1;
  m_color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
  return;
}

sf::Vector2f Food::getPosition() const
{
  return m_position;
}

void Food::renderFood(sf::RenderWindow& l_window)
{
  int offset = 10;
  sf::RectangleShape food_box(sf::Vector2f(m_size - offset,m_size - offset));
  food_box.setOrigin(sf::Vector2f(m_size/2,m_size/2));
  food_box.setPosition(sf::Vector2f(m_position.x * m_size,m_position.y * m_size));
  food_box.setFillColor(m_color);
  l_window.draw(food_box);
  return;
}

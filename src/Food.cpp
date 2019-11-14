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

void Food::setSize(const int& l_size)
{
  m_size = l_size;
  return;
}

void Food::init(const int& l_size)
{
  srand(time(0));
  m_size = l_size;
  m_position.x =  rand() % 47 + 1;
  m_position.y =  rand() % 26 + 1;
  m_color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
  return;
}

void Food::generate(const Snake& l_snake)
{

  m_color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
  do
  {
    m_position.x = rand() % 47 + 1;
    m_position.y = rand() % 26 + 1;

  }while(l_snake.isColliding(sf::Vector2f(m_position)));

  return;
}

void Food::render(sf::RenderWindow& l_window)
{
  int offset = 10;
  sf::RectangleShape food_box(sf::Vector2f(m_size - offset,m_size - offset));
  food_box.setOrigin(sf::Vector2f(m_size/2,m_size/2));
  food_box.setPosition(sf::Vector2f(m_position.x * m_size,m_position.y * m_size));
  food_box.setFillColor(m_color);
  l_window.draw(food_box);
  return;
}

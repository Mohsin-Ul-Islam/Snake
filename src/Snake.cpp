#include "Snake/Snake.h"

Snake::Snake()
{
  init(10,3);
}

Snake::Snake(const int& l_size, const int& l_lives)
{
  init(l_size,l_lives);
}

Snake::~Snake()
{

}

void Snake::init(const int& l_size, const int& l_lives)
{
  m_lives = l_lives;
  m_size  = l_size;
  m_dir   = Direction::NONE;
  m_snakeBody.push_back(snakePiece(12,10));
  m_snakeBody.push_back(snakePiece(11,10));
  m_snakeBody.push_back(snakePiece(10,10));
  return;
}

void Snake::setDirection(const Direction& l_dir)
{
  m_dir = l_dir;
  return;
}

void Snake::renderSnake(sf::RenderWindow& l_window)
{
  int offset = 10;
  sf::Color prev = sf::Color::Yellow;
  for(int i = 0; i<m_snakeBody.size(); i++)
  {
    sf::RectangleShape piece(sf::Vector2f(m_size - offset,m_size - offset));
    piece.setOrigin(sf::Vector2f(m_size/2.0,m_size/2.0));
    piece.setPosition(sf::Vector2f(m_snakeBody[i].x * m_size,m_snakeBody[i].y * m_size));
    if(i == 0)
    {
      piece.setFillColor(prev);
    }
    else
    {
      sf::Color now = sf::Color(prev.r/i,prev.g/i,prev.b/i);
      piece.setFillColor(now);
      prev = now;
    }
    l_window.draw(piece);
  }
  return;
}

void Snake::grow()
{

  snakePiece tail     = m_snakeBody.back();
  snakePiece tailNeck = m_snakeBody[m_snakeBody.size() - 2];
  snakePiece toInsert(0,0);

  if(tail.y == tailNeck.y)
  {
    toInsert.y = tail.y;
    if(tail.x > tailNeck.x)
    {
      toInsert.x = tail.x + 1;
    }
    else if(tail.x < tailNeck.x)
    {
      toInsert.x = tail.x - 1;
    }
  }
  else if(tail.x == tailNeck.y)
  {
    toInsert.x = tail.x;
    if(tail.y > tailNeck.y)
    {
      toInsert.y = tail.y + 1;
    }
    else if(tail.y < tailNeck.y)
    {
      toInsert.y = tail.y - 1;
    }
  }
  m_snakeBody.push_back(toInsert);
  return;
}

void Snake::move()
{
  if(m_dir == Direction::NONE)
  {
    return;
  }
  else if(m_dir == Direction::UP)
  {
    snakePiece snakeHead = m_snakeBody.front();
    snakeHead.y -= 1;
    for(int i = m_snakeBody.size() - 1; i<m_snakeBody.size(); i++)
    {
      m_snakeBody[i] = m_snakeBody[i + 1];
    }
    m_snakeBody.pop_back();
    m_snakeBody.push_front(snakeHead);
  }
  else if(m_dir == Direction::DOWN)
  {
    snakePiece snakeHead = m_snakeBody[0];
    snakeHead.y += 1;
    for(int i = m_snakeBody.size() - 1; i<m_snakeBody.size(); i++)
    {
      m_snakeBody[i] = m_snakeBody[i + 1];
    }
    m_snakeBody.pop_back();
    m_snakeBody.insert(m_snakeBody.begin(),snakeHead);
  }
  else if(m_dir == Direction::LEFT)
  {
    snakePiece snakeHead = m_snakeBody[0];
    snakeHead.x -= 1;
    for(int i = m_snakeBody.size() - 1; i<m_snakeBody.size(); i++)
    {
      m_snakeBody[i] = m_snakeBody[i + 1];
    }
    m_snakeBody.pop_back();
    m_snakeBody.insert(m_snakeBody.begin(),snakeHead);
  }
  else if(m_dir == Direction::RIGHT)
  {
    snakePiece snakeHead = m_snakeBody[0];
    snakeHead.x += 1;
    for(int i = m_snakeBody.size() - 1; i<m_snakeBody.size(); i++)
    {
      m_snakeBody[i] = m_snakeBody[i + 1];
    }
    m_snakeBody.pop_back();
    m_snakeBody.insert(m_snakeBody.begin(),snakeHead);
  }

  return;
}

Direction Snake::getDirection() const
{
  return m_dir;
}

Direction Snake::getCalculatedDirection() const
{
  if(m_snakeBody.size() < 3) return m_dir;

  snakePiece snakeHead = m_snakeBody[0];
  snakePiece snakeNeck = m_snakeBody[1];

  if(snakeHead.y == snakeNeck.y)
  {
    if(snakeHead.x < snakeNeck.x)
    {
      return Direction::LEFT;
    }
    else if(snakeHead.x > snakeNeck.x)
    {
      return Direction::RIGHT;
    }
  }
  else if(snakeHead.x == snakeNeck.x)
  {
    if(snakeHead.y > snakeNeck.y)
    {
      return Direction::DOWN;
    }
    else if(snakeHead.y < snakeNeck.y)
    {
      return Direction::UP;
    }
  }

  return Direction::NONE;
}

sf::Vector2f Snake::getPosition() const
{
  return sf::Vector2f(m_snakeBody.front().x,m_snakeBody.front().y);
}

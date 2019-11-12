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
  m_halt = false;
  m_score = 0;
  return;
}

void Snake::setDirection(const Direction& l_dir)
{
  m_dir = l_dir;
  return;
}

void Snake::setLivesCount(const int& l_lives)
{
  m_lives = l_lives;
  return;
}

void Snake::setSize(const int& l_size)
{
  m_size = l_size;
  return;
}

void Snake::render(sf::RenderWindow& l_window)
{
  int offset = 10;
  for(int i = 0; i<m_snakeBody.size(); i++)
  {
    sf::RectangleShape piece(sf::Vector2f(m_size - offset,m_size - offset));
    piece.setOrigin(sf::Vector2f(m_size/2.0,m_size/2.0));
    piece.setPosition(sf::Vector2f(m_snakeBody[i].x * m_size,m_snakeBody[i].y * m_size));
    if(i == 0)
    {
      piece.setFillColor(sf::Color::Red);
    }
    else
    {
      piece.setFillColor(sf::Color::White);
    }
    l_window.draw(piece);
  }

  return;
}

bool Snake::isColliding(const sf::Vector2f& l_point) const
{
  for(int i = 0; i<m_snakeBody.size(); i++)
  {
    if(l_point.x == m_snakeBody[i].x && m_snakeBody[i].y == l_point.y)
    {
      return true;
    }
  }
  return false;
}

void Snake::grow()
{

  snakePiece tail     = m_snakeBody.back();
  snakePiece tailNeck = m_snakeBody[m_snakeBody.size() - 2];
  snakePiece toInsert(0,0);
  m_score += 1;

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

void Snake::halt()
{
  m_halt = true;
}

void Snake::move()
{
  if(m_dir == Direction::NONE || m_halt)
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

  int index = selfColliding();

  if(index)
  {
    m_lives -= 1;
    for(int i = m_snakeBody.size() - 1; i>=index; i--)
    {
      m_snakeBody.pop_back();
    }
  }

  return;
}

int Snake::selfColliding() const
{
  snakePiece snakeHead = m_snakeBody[0];

  for(int i = 1; i<m_snakeBody.size(); i++)
  {
    if(m_snakeBody[i].x == snakeHead.x && m_snakeBody[i].y == snakeHead.y)
    {
      return i;
    }
  }
  return 0;
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

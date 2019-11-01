#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream>

enum Direction
{
  UP,DOWN,LEFT,RIGHT,NONE
};

struct snakePiece
{
  snakePiece(int a, int b)
  {
    x = a;
    y = b;
  }

  int x;
  int y;
};

class Snake
{

  public:

    Snake();
    Snake(const int& l_size, const int& l_lives);
    void setDirection(const Direction& l_dir);
    void grow();
    void move();
    void renderSnake(sf::RenderWindow& l_window);
    sf::Vector2f getPosition() const;
    Direction getDirection() const;
    Direction getCalculatedDirection() const;
    ~Snake();

  private:

    void init(const int& l_size, const int& l_lives);

    int       m_lives;
    int       m_size;
    Direction m_dir;
    std::deque<snakePiece> m_snakeBody;



};

#endif

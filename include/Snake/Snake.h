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

    void grow();
    void move();
    void halt();

    void setDirection(const Direction& l_dir);
    void render(sf::RenderWindow& l_window);
    void setLivesCount(const int& l_lives);
    void setSize(const int& l_size);

    inline sf::Vector2f getPosition() const {return sf::Vector2f(m_snakeBody[0].x,m_snakeBody[0].y);};
    inline Direction getDirection() const {return m_dir;};
    inline bool isDead() const {return m_lives == 0;};
    inline int getLives() const {return m_lives;};
    inline int getScore() const {return m_score;};

    Direction getCalculatedDirection() const;
    bool isColliding(const sf::Vector2f& l_point) const;

    ~Snake();

  private:

    void init(const int& l_size, const int& l_lives);
    int selfColliding() const;

    int       m_lives;
    int       m_size;
    int       m_score;
    Direction m_dir;
    bool      m_halt;
    std::deque<snakePiece> m_snakeBody;



};

#endif

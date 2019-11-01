#include <iostream>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Snake/Window.h"
#include "Snake/Snake.h"

int main(int argc, char* argv[])
{

    srand(time(0));

    const int WIDTH     = 980;
    const int HEIGHT    = 640;
    const int FRAMERATE = 60;

    Window window(WIDTH,HEIGHT,"Snake Game");
    window.self()->setFramerateLimit(FRAMERATE);

    Snake snake(50,3);

    sf::Clock clock;


    float delay = 0.1f;
    float accumulatedTime = 0;

    while(window.live())
    {
      accumulatedTime += clock.getElapsedTime().asSeconds();
      clock.restart();
      sf::Event event;
      window.self()->pollEvent(event);
      if(event.type == sf::Event::Closed) window.self()->close();
      if(event.type == sf::Event::KeyPressed)
      {
        if(event.key.code == sf::Keyboard::Up && snake.getCalculatedDirection() != Direction::UP)
        {
          snake.setDirection(Direction::UP);
        }
        else if(event.key.code == sf::Keyboard::Down && snake.getCalculatedDirection() != Direction::DOWN)
        {
          snake.setDirection(Direction::DOWN);
        }
        else if(event.key.code == sf::Keyboard::Left && snake.getCalculatedDirection() != Direction::LEFT)
        {
          snake.setDirection(Direction::LEFT);
        }
        else if(event.key.code == sf::Keyboard::Right && snake.getCalculatedDirection() != Direction::RIGHT)
        {
          snake.setDirection(Direction::RIGHT);
        }
      }

      if(accumulatedTime >= delay)
      {
        accumulatedTime = 0;
        snake.move();
      }
      window.erase();
      snake.renderSnake(*window.self());
      window.show();
    }

    return 0;

}

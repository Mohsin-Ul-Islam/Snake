#include <iostream>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Snake/Window.h"
#include "Snake/Snake.h"
#include "Snake/Food.h"

int main(int argc, char* argv[])
{

    const int WIDTH     = 1000;
    const int HEIGHT    = 600;
    const int FRAMERATE = 60;

    Window window(WIDTH,HEIGHT,"Snake Game");
    window.self()->setFramerateLimit(FRAMERATE);

    Snake snake(40,3);
    Food  food(40);

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

      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getCalculatedDirection() != Direction::DOWN)
      {
        snake.setDirection(Direction::UP);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getCalculatedDirection() != Direction::UP)
      {
        snake.setDirection(Direction::DOWN);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getCalculatedDirection() != Direction::RIGHT)
      {
        snake.setDirection(Direction::LEFT);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getCalculatedDirection() != Direction::LEFT)
      {
        snake.setDirection(Direction::RIGHT);
      }

      if(accumulatedTime >= delay)
      {
        accumulatedTime = 0;
        snake.move();
      }

      if(snake.getPosition().x == food.getPosition().x && snake.getPosition().y == food.getPosition().y)
      {
        food.generate();
        snake.grow();
      }
      window.erase();
      snake.renderSnake(*window.self());
      food.renderFood(*window.self());
      window.show();
    }

    return 0;

}

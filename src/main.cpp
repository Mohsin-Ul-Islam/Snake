#include <sstream>
#include "Snake/Window.h"
#include "Snake/Snake.h"
#include "Snake/Food.h"
#include "Snake/AssetManager.h"

std::string toString(const int& l_val)
{
  std::stringstream converter;
  converter<<l_val;
  std::string result;
  converter>>result;
  return result;
}

int main(int argc, char* argv[])
{

    const int WIDTH     = 1000;
    const int HEIGHT    = 600;
    const int FRAMERATE = 80;

    Window window(WIDTH,HEIGHT,"Snake Game");
    //window.self()->setFramerateLimit(FRAMERATE);
    //window.self()->setVerticalSyncEnabled(true);

    AssetManager manager;

    Snake snake(40,3);
    Food  food(40);

    std::string log;

    sf::Clock clock;

    sf::Font font;
    font.loadFromFile("../assets/fonts/Roboto/Roboto-Black.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(10,10));

    int frames = 0;
    float frameTime = 0;


    float delay = 0.1f;
    float accumulatedTime = 0;

    while(window.live())
    {
      frames += 1;
      accumulatedTime += clock.getElapsedTime().asSeconds();
      frameTime += clock.getElapsedTime().asSeconds();
      clock.restart();
      int frameRate = frames/frameTime;
      if(frameTime >= 1)
      {
        frames = 0;
        frameTime -= 1;
      }
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
        accumulatedTime -= delay;
        snake.move();
      }

      if(snake.getPosition().x == food.getPosition().x && snake.getPosition().y == food.getPosition().y)
      {
        food.generate(snake);
        snake.grow();
      }

      if(!snake.getLives())
      {
        snake.halt();
        log += "Game over!";
      }
      log += "Lives Remaining: " + toString(snake.getLives()) + "| Score: " + toString(snake.getScore()) + "| Frame Rate: " + toString(frameRate);
      text.setString(log);
      window.erase();
      snake.render(*window.self());
      food.render(*window.self());
      window.render(text);
      window.show();
      log = "";
    }

    return 0;

}

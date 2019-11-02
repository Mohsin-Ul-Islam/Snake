#include <sstream>
#include "Snake/Game.h"

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

    Game myGame;

    myGame.setFrameRate(60);
    myGame.setWindowName("Snake Game");
    myGame.setEntitySize(40);
    myGame.setWindowWidth(980);
    myGame.setWindowHeight(640);
    myGame.initialize();

    sf::Clock clock;

    float delay = 0.1f;
    float accum = 0.0f;

    while(!myGame.isEnd())
    {
      accum += clock.getElapsedTime().asSeconds();
      clock.restart();
      myGame.handleInput();
      if(accum >= delay)
      {
        accum -= delay;
        myGame.update();
      }
      myGame.render();
    }


    return 0;

}

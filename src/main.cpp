#include "Snake/Game.h"



int main(int argc, char* argv[])
{



    Game myGame;

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

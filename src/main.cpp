#include "Snake/Game.h"



int main(int argc, char* argv[])
{



    Game myGame;

    myGame.initialize();

    sf::Clock clock;
    
    float accum = 0.0f;

    while(!myGame.isEnd())
    {
      accum += clock.getElapsedTime().asSeconds();
      clock.restart();
      myGame.handleInput();
      myGame.update(accum);
      myGame.render();
    }

    return 0;

}

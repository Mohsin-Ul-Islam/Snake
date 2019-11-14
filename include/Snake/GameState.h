#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<SFML/Graphics.hpp>

class GameState
{

  public:

    void render(sf::RenderWindow& l_window);
    void setActive();
    inline bool isActive() const {return m_active;};

  private:

    bool m_active;

};

#endif

#ifndef GAME_H
#define GAME_H

#include <sstream>
#include "Snake/Window.h"
#include "Snake/World.h"
#include "Snake/AssetManager.h"
#include "Globals.h"

class Game
{

  public:

    Game();
    void initialize();
    void update();
    void render();
    void handleInput();
    inline bool isEnd() const {return m_isEnd;};
    inline World* world() {return m_world;};
    inline Window* window() {return m_window;};
    ~Game();

  private:

    std::string toString(const int& l_val);


    bool         m_isEnd;
    World*        m_world;
    Window*       m_window;
    AssetManager* m_manager;

    std::deque<std::string> m_messages;

    sf::Sound m_food_eaten;
    sf::Text  m_text;

};

#endif

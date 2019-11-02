#ifndef GAME_H
#define GAME_H

#include "Snake/Window.h"
#include "Snake/World.h"
#include "Snake/AssetManager.h"
#include "Globals.h"

class Game
{

  public:

    Game();
    void initialize();
    void setFrameRate(const int& l_frames);
    void setWindowName(const std::string& l_name);
    void setEntitySize(const int& l_size);
    void setWindowWidth(const int& l_width);
    void setWindowHeight(const int& l_height);
    void update();
    void render();
    void handleInput();
    inline bool isEnd() const {return m_isEnd;};
    inline World* world() {return m_world;};
    inline Window* window() {return m_window;};
    ~Game();

  private:

    bool         m_isEnd;
    World*        m_world;
    Window*       m_window;
    AssetManager* m_manager;

};

#endif

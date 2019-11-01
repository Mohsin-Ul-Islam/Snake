#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

class Window
{

  public:

    Window(const int& l_width, const int& l_height, const std::string& l_name);
    void resize(const int& l_width, const int& l_height);
    void toggleFullScreen();
    void render(const sf::Drawable& l_entity);
    void erase();
    void show();
    bool live() const;
    sf::RenderWindow* self();
    ~Window();

  private:

    void create();
    void destroy();

    int m_width;
    int m_height;
    std::string m_name;
    bool m_fullScreen;
    sf::RenderWindow m_window;

};

#endif

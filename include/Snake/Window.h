#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Window
{

  public:

    Window();
    Window(const int& l_width, const int& l_height, const std::string& l_name);
    void resize(const int& l_width, const int& l_height);
    void toggleFullScreen() ;
    void render(const sf::Drawable& l_entity);
    void erase(const sf::Color& l_color);
    void show();
    void create();
    inline bool live() const {return m_window.isOpen();};
    inline sf::RenderWindow* self() {return &m_window;};
    ~Window();

  private:

    void destroy();

    int m_width;
    int m_height;
    std::string m_name;
    bool m_fullScreen;
    sf::RenderWindow m_window;

};

#endif

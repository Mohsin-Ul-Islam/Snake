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
    void setFrameRate(const int& l_frames);
    void setName(const std::string& l_name);
    void setWidth(const int& l_width);
    void setHeight(const int& l_height);
    void create();
    inline bool live() const {return m_window.isOpen();};
    inline sf::RenderWindow* self() {return &m_window;};
    ~Window();

  private:

    void destroy();

    int m_width;
    int m_height;
    int m_frames;
    std::string m_name;
    bool m_fullScreen;
    sf::RenderWindow m_window;

};

#endif

#include "Snake/Window.h"


Window::Window()
{
  
}

Window::Window(const int& l_width, const int& l_height, const std::string& l_name)
{
  m_width  = l_width;
  m_height = l_height;
  m_name   = l_name;
  m_fullScreen = false;
  create();
}

Window::~Window()
{
  destroy();
}

void Window::destroy()
{
  m_window.close();
  return;
}

void Window::create()
{
  if(m_fullScreen)
  {
    m_window.create(sf::VideoMode(1920,1080),m_name,sf::Style::Fullscreen);
  }
  else
  {
    m_window.create(sf::VideoMode(m_width,m_height),m_name);
  }

  m_window.setFramerateLimit(m_frames);

  return;
}

void Window::setFrameRate(const int& l_frames)
{
  m_frames = l_frames;
  return;
}

void Window::setName(const std::string& l_name)
{
  m_name = l_name;
  return;
}

void Window::setWidth(const int& l_width)
{
  m_width = l_width;
  return;
}

void Window::setHeight(const int& l_height)
{
  m_height = l_height;
  return;
}

void Window::toggleFullScreen()
{
  destroy();
  m_fullScreen = !m_fullScreen;
  create();
  return;
}

void Window::resize(const int& l_width, const int& l_height)
{
  m_width  = l_width;
  m_height = l_height;
  destroy();
  create();
  return;
}

void Window::render(const sf::Drawable& l_entity)
{
  m_window.draw(l_entity);
  return;
}

void Window::erase(const sf::Color& l_color)
{
  m_window.clear(l_color);
  return;
}

void Window::show()
{
  m_window.display();
  return;
}

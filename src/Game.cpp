#include "Snake/Game.h"

Game::Game()
{
  m_world   = new World;
  m_window  = new Window;
  m_manager = new AssetManager;
}

Game::~Game()
{

}

void Game::initialize()
{
  m_isEnd = false;
  m_window->create();
}

void Game::setFrameRate(const int& l_frames)
{
  m_window->setFrameRate(l_frames);
}

void Game::setWindowWidth(const int& l_width)
{
  m_window->setWidth(l_width);
  return;
}

void Game::setWindowHeight(const int& l_height)
{
  m_window->setHeight(l_height);
  return;
}

void Game::setEntitySize(const int& l_size)
{
  m_world->setEntitySize(l_size);
}

void Game::setWindowName(const std::string& l_name)
{
  m_window->setName(l_name);
}

void Game::handleInput()
{
  sf::Event event;

  m_window->self()->pollEvent(event);

  if(event.type == sf::Event::Closed)
  {
    m_isEnd = true;
    m_window->self()->close();
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_world->snake().getCalculatedDirection() != Direction::DOWN)
  {
    m_world->snake().setDirection(Direction::UP);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_world->snake().getCalculatedDirection() != Direction::UP)
  {
    m_world->snake().setDirection(Direction::DOWN);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_world->snake().getCalculatedDirection() != Direction::RIGHT)
  {
    m_world->snake().setDirection(Direction::LEFT);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_world->snake().getCalculatedDirection() != Direction::LEFT)
  {
    m_world->snake().setDirection(Direction::RIGHT);
  }
}

void Game::update()
{
  m_world->snake().move();

  if(m_world->snake().getPosition().x == m_world->food().getPosition().x && m_world->snake().getPosition().y == m_world->food().getPosition().y)
  {
    //food_eat.play();
    m_world->food().generate(m_world->snake());
    m_world->snake().grow();
  }

  if(!m_world->snake().getLives())
  {
    m_world->snake().halt();
    m_isEnd = true;
  }
}

void Game::render()
{
  m_window->erase(sf::Color::White);
  m_world->render(*m_window->self());
  m_window->show();
  return;
}

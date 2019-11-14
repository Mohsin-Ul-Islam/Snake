#include "Snake/GameState.h"

GameState::GameState()
{
  m_active = false;
}

GameState::~GameState()
{

}

void GameState::setActive()
{
  m_active = true;
}

void GameState::render(sf::RenderWindow& l_window)
{
  
}

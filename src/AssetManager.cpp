#include "Snake/AssetManager.h"

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{

}

bool AssetManager::inTextures(const std::string& l_tex)
{
  for(auto itr = m_textures.begin(); itr != m_textures.end(); itr++)
  {
    if(itr->first == l_tex)
    {
      return true;
    }
  }
  return false;
}

bool AssetManager::inFonts(const std::string& l_font)
{
  for(auto itr = m_fonts.begin(); itr != m_fonts.end(); itr++)
  {
    if(itr->first == l_font)
    {
      return true;
    }
  }
  return false;
}

bool AssetManager::inSounds(const std::string& l_sound)
{
  for(auto itr = m_sounds.begin(); itr != m_sounds.end(); itr++)
  {
    if(itr->first == l_sound)
    {
      return true;
    }
  }
  return false;
}

void AssetManager::addTexture(const std::string& l_tex)
{
  if(!inTextures(l_tex))
  {
    sf::Texture texture;
    if(texture.loadFromFile(l_tex)) m_textures[l_tex] = texture;
  }
  return;
}

void AssetManager::removeTexture(const std::string& l_tex)
{
  if(inTextures(l_tex)) m_textures.erase(l_tex);
  return;
}

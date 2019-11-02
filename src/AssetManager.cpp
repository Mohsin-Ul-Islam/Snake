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
    console.log("Texture " + l_tex + " loaded.");
  }
  return;
}

void AssetManager::addFont(const std::string& l_font)
{
  if(!inFonts(l_font))
  {
    sf::Font font;
    if(font.loadFromFile(l_font)) m_fonts[l_font] = font;
    console.log("Font " + l_font + " loaded.");
  }
  return;
}

void AssetManager::addSound(const std::string& l_sound)
{
  if(!inSounds(l_sound))
  {
    sf::SoundBuffer sound;
    if(sound.loadFromFile(l_sound)) m_sounds[l_sound] = sound;
    console.log("Sound " + l_sound + " loaded.");
  }
  return;
}


void AssetManager::removeTexture(const std::string& l_tex)
{
  if(inTextures(l_tex)) m_textures.erase(l_tex);
  return;
}

void AssetManager::removeFont(const std::string& l_font)
{
  if(inFonts(l_font)) m_fonts.erase(l_font);
  return;
}

void AssetManager::removeSound(const std::string& l_sound)
{
  if(inSounds(l_sound)) m_sounds.erase(l_sound);
  return;
}

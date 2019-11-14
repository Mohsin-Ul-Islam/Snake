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

bool AssetManager::inSoundBuffers(const std::string& l_sound_buffer)
{
  for(auto itr = m_sound_buffers.begin(); itr != m_sound_buffers.end(); itr++)
  {
    if(itr->first == l_sound_buffer)
    {
      return true;
    }
  }
  return false;
}

void AssetManager::addTexture(const std::string& l_tex, const std::string& l_path)
{
  if(!inTextures(l_tex))
  {
    sf::Texture texture;
    if(texture.loadFromFile(l_path)) m_textures[l_tex] = texture;
    console.log("Texture " + l_tex + " loaded.");
  }
  return;
}

void AssetManager::addFont(const std::string& l_font, const std::string& l_path)
{
  if(!inFonts(l_font))
  {
    sf::Font font;
    if(font.loadFromFile(l_path)) m_fonts[l_font] = font;
    console.log("Font " + l_font + " loaded.");
  }
  return;
}

void AssetManager::addSoundBuffer(const std::string& l_sound_buffer, const std::string& l_path)
{
  if(!inSoundBuffers(l_sound_buffer))
  {
    sf::SoundBuffer sound_buffer;
    if(sound_buffer.loadFromFile(l_path)) m_sound_buffers[l_sound_buffer] = sound_buffer;
    console.log("Sound " + l_sound_buffer + " loaded.");
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

void AssetManager::removeSoundBuffer(const std::string& l_sound_buffer)
{
  if(inSoundBuffers(l_sound_buffer)) m_sound_buffers.erase(l_sound_buffer);
  return;
}

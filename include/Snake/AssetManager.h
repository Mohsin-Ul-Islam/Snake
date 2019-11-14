#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<map>
#include "Console/Console.h"

class AssetManager
{

  public:

    AssetManager();
    ~AssetManager();

    void addTexture(const std::string& l_tex, const std::string& l_path);
    void addFont(const std::string& l_font, const std::string& l_path);
    void addSoundBuffer(const std::string& l_sound_buffer, const std::string& l_path);

    void removeTexture(const std::string& l_tex);
    void removeFont(const std::string& l_font);
    void removeSoundBuffer(const std::string& l_sound_buffer);

    void clean();

    inline sf::Texture& getTexture(const std::string& l_tex)  {return m_textures.at(l_tex);};
    inline sf::Font& getFont(const std::string& l_font)  {return m_fonts.at(l_font);};
    inline sf::SoundBuffer& getSoundBuffer(const std::string& l_sound_buffer)  {return m_sound_buffers.at(l_sound_buffer);};

  private:

    bool inTextures(const std::string& l_tex);
    bool inFonts(const std::string& l_font);
    bool inSoundBuffers(const std::string& l_sound);

    std::map<std::string,sf::Texture> m_textures;
    std::map<std::string,sf::Font> m_fonts;
    std::map<std::string,sf::SoundBuffer> m_sound_buffers;
};

#endif

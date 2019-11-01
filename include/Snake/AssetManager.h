#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<map>

class AssetManager
{

  public:

    AssetManager();
    ~AssetManager();

    void addTexture(const std::string& l_tex);
    void addFont(const std::string& l_font);
    void addSound(const std::string& l_sound);

    void removeTexture(const std::string& l_tex);
    void removeFont(const std::string& l_font);
    void removeSound(const std::string& l_sound);

    void clean();

    inline sf::Texture getTexture(const std::string& l_tex) const {return m_textures.at(l_tex);};
    inline sf::Font getFont(const std::string& l_font) const {return m_fonts.at(l_font);};
    inline sf::Sound getSound(const std::string& l_sound) const {return m_sounds.at(l_sound);};

  private:

    bool inTextures(const std::string& l_tex);
    bool inFonts(const std::string& l_font);
    bool inSounds(const std::string& l_sound);

    std::map<std::string,sf::Texture> m_textures;
    std::map<std::string,sf::Font> m_fonts;
    std::map<std::string,sf::Sound> m_sounds;
};

#endif

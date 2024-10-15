#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>


class AssetManager {
public:
    static std::map<std::string, sf::Texture> Textures;
    static std::map<std::string, sf::Sound> Sounds;
    static std::map<std::string, sf::Music*> Music;
    static std::map<std::string, sf::Font> Fonts;

    // Load Texture
    static void LoadTexture(const std::string& name, const std::string& fileName);

    // Load Sound
    static void LoadSound(const std::string& name, const std::string& fileName);
        

    // Load Music
    static void LoadMusic(const std::string& name, const std::string& fileName);

    // Load Font
    static void LoadFont(const std::string& name, const std::string& fileName);
};

// Definition der statischen Mitglieder
std::map<std::string, sf::Texture> AssetManager::Textures;
std::map<std::string, sf::Sound> AssetManager::Sounds;
std::map<std::string, sf::Music*> AssetManager::Music;
std::map<std::string, sf::Font> AssetManager::Fonts;

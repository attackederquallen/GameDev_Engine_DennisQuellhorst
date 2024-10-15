

#include "AssetManager.h"
    

        // Load Texture
         void AssetManager::LoadTexture(const std::string& name, const std::string& fileName) {
            if (Textures.find(name) != Textures.end())
                return;

            sf::Texture texture;
            if (texture.loadFromFile(fileName)) {
                Textures[name] = texture;
            }
        }

        // Load Sound
         void AssetManager::LoadSound(const std::string& name, const std::string& fileName) {
            if (Sounds.find(name) != Sounds.end())
                return;

            sf::SoundBuffer buffer;
            if (buffer.loadFromFile(fileName)) {
                Sounds[name] = sf::Sound(buffer);
            }
        }

        // Load Music
         void AssetManager::LoadMusic(const std::string& name, const std::string& fileName) {
            if (Music.find(name) != Music.end())
                return;

            sf::Music* music = new sf::Music();
            if (music->openFromFile(fileName)) {
                Music[name] = music;
            }
        }

        // Load Font
        void AssetManager::LoadFont(const std::string& name, const std::string& fileName) {
            if (Fonts.find(name) != Fonts.end())
                return;

            sf::Font font;
            if (font.loadFromFile(fileName)) {
                Fonts[name] = font;
            }
        }
    

    // Definition der statischen Mitglieder
    std::map<std::string, sf::Texture> AssetManager::Textures;
    std::map<std::string, sf::Sound> AssetManager::Sounds;
    std::map<std::string, sf::Music*> AssetManager::Music;
    std::map<std::string, sf::Font> AssetManager::Fonts;


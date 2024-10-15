#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class InputManager {
private:
    static InputManager* instance;
    std::unordered_map<sf::Keyboard::Key, bool> isKeyDown;
    std::unordered_map<sf::Keyboard::Key, bool> isKeyPressed;
    std::unordered_map<sf::Keyboard::Key, bool> isKeyUp;

    InputManager() {
        // Initialize all keys to false
        isKeyDown[sf::Keyboard::W] = false;
        isKeyDown[sf::Keyboard::A] = false;
        isKeyDown[sf::Keyboard::S] = false;
        isKeyDown[sf::Keyboard::D] = false;
        isKeyDown[sf::Keyboard::Space] = false;
        isKeyDown[sf::Keyboard::Num1] = false;
        isKeyDown[sf::Keyboard::Num2] = false;

        isKeyUp[sf::Keyboard::W] = false;
        isKeyUp[sf::Keyboard::A] = false;
        isKeyUp[sf::Keyboard::S] = false;
        isKeyUp[sf::Keyboard::D] = false;
        isKeyUp[sf::Keyboard::Space] = false;
        isKeyUp[sf::Keyboard::Num1] = false;
        isKeyUp[sf::Keyboard::Num2] = false;

        isKeyPressed[sf::Keyboard::W] = false;
        isKeyPressed[sf::Keyboard::A] = false;
        isKeyPressed[sf::Keyboard::S] = false;
        isKeyPressed[sf::Keyboard::D] = false;
        isKeyPressed[sf::Keyboard::Space] = false;
        isKeyPressed[sf::Keyboard::Num1] = false;
        isKeyPressed[sf::Keyboard::Num2] = false;
    }

public:
    // Singleton pattern
    static InputManager& Instance() {
        if (instance == nullptr) {
            instance = new InputManager();
        }
        return *instance;
    }

    void Init(sf::Window& window);

    void Update();

    

    bool GetKeyPressed(sf::Keyboard::Key key);

    bool GetKeyDown(sf::Keyboard::Key key);

    bool GetKeyUp(sf::Keyboard::Key key);

    void OnKeyPressed(const sf::Event::KeyEvent& event);

    void OnKeyReleased(const sf::Event::KeyEvent& event);
};


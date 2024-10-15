#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "InputManager.h"



    void InputManager::Init(sf::Window& window) {
        window.setKeyRepeatEnabled(false);
    }

     void InputManager::Update() {
        for (auto& kvp : isKeyDown) {
            kvp.second = false;
        }

        for (auto& kvp : isKeyUp) {
            kvp.second = false;
        }
    }

    bool InputManager::GetKeyPressed(sf::Keyboard::Key key) {
        return isKeyPressed.count(key) ? isKeyPressed[key] : false;
    }

    bool InputManager::GetKeyDown(sf::Keyboard::Key key) {
        return isKeyDown.count(key) ? isKeyDown[key] : false;
    }

    bool InputManager::GetKeyUp(sf::Keyboard::Key key) {
        return isKeyUp.count(key) ? isKeyUp[key] : false;
    }

    void InputManager::OnKeyPressed(const sf::Event::KeyEvent& event) {
        if (isKeyPressed.count(event.code)) {
            isKeyDown[event.code] = true;
            isKeyPressed[event.code] = true;
        }
    }

    void InputManager::OnKeyReleased(const sf::Event::KeyEvent& event) {
        if (isKeyPressed.count(event.code)) {
            isKeyUp[event.code] = true;
            isKeyPressed[event.code] = false;
        }
    }


// Initialize the static instance
InputManager* InputManager::instance = nullptr;
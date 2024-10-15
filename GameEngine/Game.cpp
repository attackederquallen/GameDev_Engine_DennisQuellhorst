#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "InputManager.h"
#include "AssetManager.h"
#include "DebugDraw.h"
#include "Player.h"
#include "GameObject.h"

class Game {
public:
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    const std::string TITLE = "GrundlagenGameDev";
    const sf::Color BG_COLOR = sf::Color(50, 50, 50);

private:
    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<GameObject*> gameObjects;
    Player* player;

public:
    Game()
        : window(sf::VideoMode(WIDTH, HEIGHT), TITLE) {
        window.setVerticalSyncEnabled(true);
        window.setKeyRepeatEnabled(false);

        // Lambda für das Schließen des Fensters
        window.setFramerateLimit(60);
    }

    void run() {
        initialize();

        while (window.isOpen()) {
            float deltaTime = clock.restart().asSeconds();
            handleEvents();
            update(deltaTime);
            draw();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                closeGame(event);
            }
        }
    }

    void closeGame(const sf::Event& event) {
        if (event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
    }

    void initialize() {
        InputManager::Instance().Init(window);
        DebugDraw::Instance().Initialize(window);

        gameObjects.clear();

        player = new Player();
        player->setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
        gameObjects.push_back(player);

        AssetManager::LoadSound("CompleteSound", "./Assets/completeSound.wav");
        AssetManager::LoadMusic("MusicTrack", "./Assets/musicTrack.ogg");
        AssetManager::GetMusic("MusicTrack").play();

        for (auto& gameObject : gameObjects) {
            gameObject->Initialize();
        }
    }

    void update(float deltaTime) {
        for (auto& gameObject : gameObjects) {
            gameObject->Update(deltaTime);
        }

        checkAreaBorders();
        InputManager::Instance().Update();
    }

    void checkAreaBorders() {
        int left = 0, top = 0;
        int right = WIDTH, bottom = HEIGHT;

        sf::FloatRect playerBounds = player->getCollisionRect();

        if (player->getPosition().y > bottom - playerBounds.height / 2) {
            player->setPosition(sf::Vector2f(player->getPosition().x, bottom - playerBounds.height / 2));
        }

        if (player->getPosition().y < top + playerBounds.height / 2) {
            player->setPosition(sf::Vector2f(player->getPosition().x, top + playerBounds.height / 2));
        }

        if (player->getPosition().x > right - playerBounds.width / 2) {
            player->setPosition(sf::Vector2f(right - playerBounds.width / 2, player->getPosition().y));
        }

        if (player->getPosition().x < left + playerBounds.width / 2) {
            player->setPosition(sf::Vector2f(left + playerBounds.width / 2, player->getPosition().y));
        }
    }

    void draw() {
        window.clear(BG_COLOR);

        drawFloor(sf::Vector2f(0, 0), sf::Vector2i(10, 10), sf::Vector2i(64, 64));

        for (auto& gameObject : gameObjects) {
            gameObject->Draw(window);
        }

        window.display();
    }

    void drawFloor(const sf::Vector2f& position, const sf::Vector2i& tiles, const sf::Vector2i& tileSize) {
        for (int x = 0; x < tiles.x; ++x) {
            for (int y = 0; y < tiles.y; ++y) {
                sf::Vector2f tilepos(position.x + x * tileSize.x, position.y + y * tileSize.y);
                DebugDraw::Instance().DrawRectangle(tilepos, tileSize.x, tileSize.y, (x + y) % 2 == 0 ? sf::Color::White : sf::Color::Black);
            }
        }
    }

    void respawnPlayer() {
        player->setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
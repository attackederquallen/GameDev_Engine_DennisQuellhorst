#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "InputManager.h"
#include "DebugDraw.h"
#include "Animationtype.h"
#include "GameObject.h"

class Player : public GameObject {
private:
    const float ANIMATION_SPEED = 8.0f;
    const int TILING_X = 10;
    const int TILING_Y = 8;
    const float MoveSpeed = 150.0f;

    sf::Sprite animatedSprite;
    int animationTypeFramesCount[8] = {3, 3, 1, 3, 10, 10, 10, 10};
    float animationTimeIndex = 0.0f;
    sf::Vector2i colliderSize = sf::Vector2i(50, 60);

    Animationtype m_animationType = Animationtype::IdleDown;

public:
    sf::IntRect CollisionRect;
    sf::IntRect PlayerCollisionRect;

    Player() {
        AssetManager::LoadTexture("Character", "./Assets/playerSpriteSheet.png");
        animatedSprite.setTexture(AssetManager::Textures["Character"]);
    }

    void Draw(sf::RenderWindow& window) override {
        DoAnimation();
        window.draw(animatedSprite);

        // Debug draw for the player sprite and collision rectangle
        DebugDraw::Instance().DrawRectOutline(
            sf::Vector2f(animatedSprite.getGlobalBounds().left, animatedSprite.getGlobalBounds().top),
            static_cast<int>(animatedSprite.getGlobalBounds().width),
            static_cast<int>(animatedSprite.getGlobalBounds().height),
            sf::Color::Red
        );
        
        DebugDraw::Instance().DrawRectOutline(CollisionRect, sf::Color::Green);
    }

    void Initialize() override {
        animatedSprite.setScale(sf::Vector2f(1.0f, 1.0f));
        animatedSprite.setPosition(sf::Vector2f(0, 0));
        animatedSprite.setTextureRect(sf::IntRect(0, 0, animatedSprite.getTextureRect().width / TILING_X, animatedSprite.getTextureRect().height / TILING_Y));

        Origin = sf::Vector2f(animatedSprite.getTextureRect().width / 2.0f, animatedSprite.getTextureRect().height / 2.0f);
        UpdateTransform();
        UpdateCollider();
    }

    void Update(float deltaTime) override {
        UpdateTransform();
        UpdateCollider();
        HandleIdle();
        HandleInput(deltaTime);

        animationTimeIndex += deltaTime * ANIMATION_SPEED;

        PlayerCollisionRect = sf::IntRect(
            static_cast<int>(Position.x),
            static_cast<int>(Position.y),
            static_cast<int>(animatedSprite.getGlobalBounds().width),
            static_cast<int>(animatedSprite.getGlobalBounds().height)
        );
    }

private:
    void UpdateTransform() {
        animatedSprite.setPosition(Position);
        animatedSprite.setRotation(Rotation);
        animatedSprite.setScale(Scale);
        animatedSprite.setOrigin(Origin);
    }

    void UpdateCollider() {
        CollisionRect = sf::IntRect(
            static_cast<int>(Position.x) - colliderSize.x / 2,
            static_cast<int>(Position.y) - colliderSize.y / 2,
            colliderSize.x,
            colliderSize.y
        );
    }

    void HandleInput(float deltaTime) {
        if (InputManager::Instance().GetKeyPressed(sf::Keyboard::W)) {
            m_animationType = Animationtype::RunUp;
            Position -= sf::Vector2f(0, 1) * MoveSpeed * deltaTime;
        }
        if (InputManager::Instance().GetKeyPressed(sf::Keyboard::A)) {
            m_animationType = Animationtype::RunLeft;
            Position -= sf::Vector2f(1, 0) * MoveSpeed * deltaTime;
        }
        if (InputManager::Instance().GetKeyPressed(sf::Keyboard::S)) {
            m_animationType = Animationtype::RunDown;
            Position += sf::Vector2f(0, 1) * MoveSpeed * deltaTime;
        }
        if (InputManager::Instance().GetKeyPressed(sf::Keyboard::D)) {
            m_animationType = Animationtype::RunRight;
            Position += sf::Vector2f(1, 0) * MoveSpeed * deltaTime;
        }
    }

    void HandleIdle() {
        if (m_animationType == Animationtype::RunUp) m_animationType = Animationtype::IdleUp;
        if (m_animationType == Animationtype::RunDown) m_animationType = Animationtype::IdleDown;
        if (m_animationType == Animationtype::RunLeft) m_animationType = Animationtype::IdleLeft;
        if (m_animationType == Animationtype::RunRight) m_animationType = Animationtype::IdleRight;
    }

    void DoAnimation() {
        int animationFrame = static_cast<int>(animationTimeIndex) % animationTypeFramesCount[static_cast<int>(m_animationType)];
        animatedSprite.setTextureRect(sf::IntRect(
            animationFrame * animatedSprite.getTextureRect().width,
            static_cast<int>(m_animationType) * animatedSprite.getTextureRect().height,
            animatedSprite.getTextureRect().width,
            animatedSprite.getTextureRect().height
        ));
    }
};
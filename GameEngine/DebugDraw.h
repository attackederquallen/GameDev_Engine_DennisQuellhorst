#pragma once
class DebugDraw {
private:
    static DebugDraw* _instance;
    sf::RenderWindow* window;

    // Private Constructor to prevent instantiation
    DebugDraw() : window(nullptr) {}

public:
    // Singleton instance getter
    static DebugDraw& Instance() {
        if (!_instance) {
            _instance = new DebugDraw();
        }
        return *_instance;
    }

    // Initialize the render window
    void Initialize(sf::RenderWindow& renderWindow);

    // Draw a line
    void DrawLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, const sf::Color& color);

    // Draw rectangle outline (manual lines)
    void DrawRectOutline(const sf::Vector2f& position, int width, int height, const sf::Color& color);

    // Draw rectangle outline (using IntRect)
    void DrawRectOutline(const sf::IntRect& intRect, const sf::Color& color);

    // Draw filled rectangle
    void DrawRectangle(const sf::Vector2f& position, int width, int height, const sf::Color& color);
    // Draw filled rectangle using IntRect
    void DrawRectangle(const sf::IntRect& rect, const sf::Color& color);
};


#include <SFML/Graphics.hpp>
#include "DebugDraw.h"



    // Initialize the render window
    void DebugDraw::Initialize(sf::RenderWindow& renderWindow) {
        this->window = &renderWindow;
    }

    // Draw a line
    void DebugDraw::DrawLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, const sf::Color& color) {
        sf::Vertex line[] = {
            sf::Vertex(startPoint, color),
            sf::Vertex(endPoint, color)
        };
        window->draw(line, 2, sf::Lines);
    }

    // Draw rectangle outline (manual lines)
    void DebugDraw::DrawRectOutline(const sf::Vector2f& position, int width, int height, const sf::Color& color) {
        sf::Vector2f bottomLeftPos(position.x, position.y + height);
        sf::Vector2f topLeftPos(position.x, position.y);
        sf::Vector2f topRightPos(position.x + width, position.y);
        sf::Vector2f bottomRightPos(position.x + width, position.y + height);

        sf::Vertex line[] = {
            sf::Vertex(bottomLeftPos, color),
            sf::Vertex(topLeftPos, color)
        };
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(topLeftPos, color);
        line[1] = sf::Vertex(topRightPos, color);
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(topRightPos, color);
        line[1] = sf::Vertex(bottomRightPos, color);
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(bottomRightPos, color);
        line[1] = sf::Vertex(bottomLeftPos, color);
        window->draw(line, 2, sf::Lines);
    }

    // Draw rectangle outline (using IntRect)
    void DebugDraw::DrawRectOutline(const sf::IntRect& intRect, const sf::Color& color) {
        sf::Vector2f position(static_cast<float>(intRect.left), static_cast<float>(intRect.top));
        int width = intRect.width;
        int height = intRect.height;

        sf::Vector2f bottomLeftPos(position.x, position.y + height);
        sf::Vector2f topLeftPos(position.x, position.y);
        sf::Vector2f topRightPos(position.x + width, position.y);
        sf::Vector2f bottomRightPos(position.x + width, position.y + height);

        sf::Vertex line[] = {
            sf::Vertex(bottomLeftPos, color),
            sf::Vertex(topLeftPos, color)
        };
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(topLeftPos, color);
        line[1] = sf::Vertex(topRightPos, color);
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(topRightPos, color);
        line[1] = sf::Vertex(bottomRightPos, color);
        window->draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(bottomRightPos, color);
        line[1] = sf::Vertex(bottomLeftPos, color);
        window->draw(line, 2, sf::Lines);
    }

    // Draw filled rectangle
    void DebugDraw::DrawRectangle(const sf::Vector2f& position, int width, int height, const sf::Color& color) {
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        window->draw(rectangle);
    }

    // Draw filled rectangle using IntRect
    void DebugDraw::DrawRectangle(const sf::IntRect& rect, const sf::Color& color) {
        sf::RectangleShape rectangle(sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height)));
        rectangle.setPosition(sf::Vector2f(static_cast<float>(rect.left), static_cast<float>(rect.top)));
        rectangle.setFillColor(color);
        window->draw(rectangle);
    }


// Initialize the static member
DebugDraw* DebugDraw::_instance = nullptr;
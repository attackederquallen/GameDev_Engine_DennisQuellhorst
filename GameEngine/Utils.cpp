#include <SFML/System.hpp>
#define M_PI 3.14159265358979323846
#include <cmath>

// Hilfsklasse für Vektormath in C++
class Utils {
public:
    // Gibt die quadrierte Länge eines Vektors zurück (vor der Quadratwurzel)
    static float SqrMagnitude(const sf::Vector2f& input) {
        return input.x * input.x + input.y * input.y;
    }

    // Dreht einen Vektor um einen gegebenen Winkel gegen den Uhrzeigersinn
    static sf::Vector2f RotateVector(const sf::Vector2f& v, float angle) {
        return sf::Vector2f(
            v.x * std::cos(angle) - v.y * std::sin(angle),
            v.x * std::sin(angle) + v.y * std::cos(angle)
        );
    }

    // Gibt den Winkel zwischen zwei Vektoren zurück (in Radianten)
    static float AngleBetween(const sf::Vector2f& v1, const sf::Vector2f& v2) {
        return std::atan2(v2.y - v1.y, v2.x - v1.x);
    }

    // Wandelt einen Wert von Radianten in Grad um
    static float ToDegrees(float val) {
        return 180.0f / M_PI * val;
    }

    // Wandelt einen Wert von Grad in Radianten um
    static float ToRadians(float val) {
        return M_PI / 180.0f * val;
    }

    // Berechnet den Abstand zwischen zwei Punkten
    static float Distance(const sf::Vector2f& a, const sf::Vector2f& b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // Normalisiert einen Vektor auf eine Länge von 1
    static sf::Vector2f Normalize(const sf::Vector2f& source) {
        float length = std::sqrt(source.x * source.x + source.y * source.y);

        if (length != 0)
            return sf::Vector2f(source.x / length, source.y / length);

        return source;
    }

    // Lineare Interpolation zwischen zwei float-Werten
    static float Lerp(float firstFloat, float secondFloat, float t, bool clamped = true) {
        if (clamped) {
            t = t > 1.0f ? 1.0f : (t < 0.0f ? 0.0f : t); // Clamp zwischen 0 und 1
        }
        return firstFloat * (1 - t) + secondFloat * t;
    }

    // Lineare Interpolation zwischen zwei Vektoren
    static sf::Vector2f Lerp(const sf::Vector2f& firstVector, const sf::Vector2f& secondVector, float t) {
        float x = Lerp(firstVector.x, secondVector.x, t);
        float y = Lerp(firstVector.y, secondVector.y, t);
        return sf::Vector2f(x, y);
    }

    // Berechnet das Skalarprodukt (Dot-Product) von zwei Vektoren
    static float Dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
};
#include <SFML/Graphics.hpp> // Header-Datei für Grafikkomponenten

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test"); // Erstelle ein Fenster

    // Hauptprogrammschleife
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Fenster leeren

        // Hier kommen deine SFML-Testfunktionen oder -operationen

        window.display(); // Fensterinhalte anzeigen
    }

    return 0;
}


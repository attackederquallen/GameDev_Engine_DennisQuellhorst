#include <iostream>
#include "Game.h"  // Angenommen, es gibt eine Game-Klasse wie in deinem Beispiel

int main() {
    std::cout << "Press ESC key to close window" << std::endl;

    // Erstelle ein neues Spiel und führe es aus
    Game game;
    game.Run();

    std::cout << "All done" << std::endl;

    return 0;
}
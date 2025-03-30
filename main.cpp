#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


void draw_grid() {
    //
}

void draw_time() {
    //
}


int main() {
    // init window
    sf::VideoMode best_mode = sf::VideoMode::getFullscreenModes()[0];
    std::cout << best_mode.size.x << "\n";
    best_mode.size = best_mode.size / 2u;
    std::cout << best_mode.size.x << "\n";

    auto window = sf::RenderWindow(best_mode, "Game of Life");
    window.setFramerateLimit(144);

    // init other graphics stuff
    sf::Clock clock;
    const sf::Font font("font.ttf");

    // init Game of Life

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event -> is <sf::Event::Closed>()) window.close();

            if (const auto* resized = event -> getIf<sf::Event::Resized>()) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear(sf::Color::White);

        sf::Vector2<float> view_size((float)best_mode.size.x, (float)best_mode.size.y);
        sf::Vector2<float> half_view_size = view_size / 2.f;
        sf::Vector2<float> offset = view_size + half_view_size; // center

        sf::RectangleShape rectangle;
        rectangle.setSize({100, 100});
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setOutlineThickness(2);
        rectangle.setPosition(half_view_size);


        sf::Text text(font, std::to_string(clock.getElapsedTime().asSeconds()));
        text.setCharacterSize(20);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Black);
        text.setPosition(half_view_size);

        window.draw(rectangle);
        window.draw(text);

        window.display();
    }
}

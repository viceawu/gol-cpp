#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
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
    best_mode.size = best_mode.size / 2u;
    std::cout << best_mode.size.x << "\n";

    auto window = sf::RenderWindow(best_mode, "Game of Life");
    
    uint frame_limit = 60;
    window.setFramerateLimit(frame_limit);

    // init grid
    sf::Vector2f cell_size = {32.f, 32.f};
    sf::Vector2f half_cell_size = cell_size / 2.f;

    sf::Vector2f view_size = sf::Vector2f(window.getSize());
    sf::Vector2f half_view_size = view_size / 2.f;
    sf::Vector2f offset = sf::Vector2f(half_view_size) - half_cell_size;

    // init Game of Life
    // ...

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event -> is <sf::Event::Closed>()) window.close();

            if (const auto* resized = event -> getIf<sf::Event::Resized>()) {
                // update the view to the new size of the window
                // std::cout << frame_size.x << " " << frame_size.y << "\n";
                view_size = sf::Vector2f(resized -> size); // TODO this f's up zoom. Zoom should be its own value.
                half_view_size = view_size / 2.f;
                offset = sf::Vector2f(half_view_size) - half_cell_size;

                sf::FloatRect visibleArea({0, 0}, view_size);
                window.setView(sf::View(visibleArea));
            }

            if (const auto* wheel = event -> getIf<sf::Event::MouseWheelScrolled>()) {
                sf::Vector2f scroll_amount(sf::Vector2f({10.f, 10.f}) * wheel -> delta); // TODO scale properly !!!
                view_size += scroll_amount;
                half_view_size = view_size / 2.f;
                offset = sf::Vector2f(half_view_size) - half_cell_size;

                sf::FloatRect visibleArea({0, 0}, sf::Vector2f(view_size));
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear(sf::Color::White);

        int x_start = -(int)half_view_size.x / cell_size.x - 1;
        int x_end = (int)half_view_size.x / cell_size.x + 2;
        
        int y_start = -(int)half_view_size.y / cell_size.y - 1;
        int y_end = (int)half_view_size.y / cell_size.y + 2;
    
        sf::RectangleShape rectangle;
        rectangle.setSize(cell_size);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setOutlineThickness(2);

        for (float x = x_start; x < x_end; x += 1) {
            for (float y = y_start; y < y_end; y += 1) {
                rectangle.setPosition(sf::Vector2f({x * cell_size.x, y * cell_size.y}) + offset);
                window.draw(rectangle);
            }
        }

        rectangle.setFillColor(sf::Color::Red);
        rectangle.setOutlineThickness(0);
        rectangle.setPosition(sf::Vector2f({0, 0}) + offset);
        window.draw(rectangle);
        
        // std::cout << " x_start: " << x_start * cell_size.x << " offset.x: " << offset.x << " view_size.x: " << view_size.x << "\n";

        window.display();
    }
}

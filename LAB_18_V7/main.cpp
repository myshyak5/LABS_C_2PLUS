#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({480u, 196u}), "SFML works!");

    sf::CircleShape circle(50.f);
    sf::RectangleShape rectangle({100.f, 100.f});
    sf::CircleShape triangle(50.f, 3.f);
    
    circle.setFillColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Cyan);
    triangle.setFillColor(sf::Color::Blue);

    circle.setOrigin({50.f, 50.f});
    rectangle.setOrigin({50.f, 50.f});
    triangle.setOrigin({50.f, 37.5f});

    circle.setPosition({50.f, 75.f});
    rectangle.setPosition({200.f, 75.f});
    triangle.setPosition({350.f, 75.f});

    rectangle.setRotation(sf::Angle(sf::degrees(45)));
    triangle.setRotation(sf::Angle(sf::degrees(90)));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.display();
    }
}

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    float cell_size = 5.0;
    sf::RenderWindow window(sf::VideoMode(530, 530), "MS Paint v8", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape cell(sf::Vector2f(cell_size, cell_size));
    // cell.setOrigin(cell_size / 2, cell_size / 2);
    cell.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case (sf::Event::Closed):
                window.close();
                break;
            default:
                break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            cell.setPosition(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
        }

        window.clear();
        // window.setFramerateLimit(120);
        window.setFramerateLimit(0);
        for (int x = 0; x < 100; x++)
        {
            for (int y = 0; y < 100; y++)
            {
                cell.setPosition(sf::Vector2f((x + 3) * cell_size, (y + 3) * cell_size));
                if ((x + y) % 2 == 0)
                {
                    cell.setFillColor(sf::Color::Red);
                }
                else if ((x + y) % 2 == 1)
                {
                    cell.setFillColor(sf::Color::Green);
                }
                else
                {
                    std::cout << "Err!";
                }

                window.draw(cell);
            }
        }
        window.display();
    }

    return 0;
}
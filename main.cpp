#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    float cell_size = 7.0;
    int cell_count = 60;
    int grid_length = cell_size * cell_count + cell_count + 2;
    sf::RectangleShape grid(sf::Vector2f(grid_length, grid_length)); // Set the bg of the cells to white
    sf::RenderWindow window(sf::VideoMode(706, 600), "Conway's Game of Life", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape cell(sf::Vector2f(cell_size, cell_size));
    // cell.setOrigin(cell_size / 2, cell_size / 2);
    cell.setFillColor(sf::Color::Black);
    grid.setFillColor(sf::Color::White);

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

        window.clear();
        float grid_x_offset = (window.getSize().x - grid_length) / 2;
        float grid_y_offset = 20.0f;
        grid.setPosition(grid_x_offset, grid_y_offset);
        window.draw(grid);

        // window.setFramerateLimit(120);
        window.setFramerateLimit(0);
        for (int x = 0; x < cell_count; x++)
        {
            for (int y = 0; y < cell_count; y++)
            {
                cell.setPosition(sf::Vector2f((x)*cell_size + x + 2 + grid_x_offset, y + 2 + (y)*cell_size + grid_y_offset));
                window.draw(cell);
            }
        }
        window.display();
    }

    return 0;
}
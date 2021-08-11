#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Sorting");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //Algorithm
    std::vector<int> nums = {66, 35, 54, 4, 51, 42, 98, 9, 20, 6, 59, 19,
                             69, 56, 73, 84, 75, 23, 55, 44, 46, 33, 27, 2, 26, 60, 14, 87, 95, 81, 16, 63, 3, 22, 45, 94, 78, 36, 12, 7, 72, 85, 30, 88, 47, 50, 86, 25, 13, 82, 80, 43, 62, 52, 11, 64, 38, 61, 68, 96, 71, 31, 83, 70, 10, 77, 28, 100, 24, 67,
                             57, 58, 89, 93, 65, 37, 90, 97, 99, 5, 21, 79, 92, 32, 1, 15, 41, 91, 29, 48, 53, 8, 49, 40, 18, 17, 74, 76, 39, 34};
    std::vector<std::vector<int>> states = {};
    states.push_back(nums);
    std::vector<int> state = states.back();
    std::vector<int> ssstate = nums;
    int temp;
    window.setMouseCursorVisible(false);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        for (int a = 0; a < nums.size() - 1; a++)
        {
            for (int b = 0; b < nums.size() - 1 - a; b++)
            {
                if (state[b] > state[b + 1])
                {
                    temp = state[b];
                    state[b] = state[b + 1];
                    state[b + 1] = temp;
                }
                // states.push_back(state);
                window.clear(sf::Color::Green);
                for (int i = 0; i < 100; i++)
                {
                    sf::Vertex line[] =
                        {
                            sf::Vertex(sf::Vector2f(40 + 2 * i, 400 - state[i])),
                            sf::Vertex(sf::Vector2f(40 + 2 * i, 400))};
                    // sf::Vertex line2[] =
                    //     {
                    //         sf::Vertex(sf::Vector2f(40 + 2 * i + 1, 400 - state[i])),
                    //         sf::Vertex(sf::Vector2f(40 + 2 * i + 1, 400))};
                    line->color = sf::Color::Red;
                    window.draw(line, 2, sf::Lines);
                    // window.draw(line2, 2, sf::Lines);
                }
                // std::cout << a << "\n";
                window.setFramerateLimit(0);
                window.display();
            }
        }
    }

    return 0;
}
#include <iostream>

// int main()
// {
//     int arr[300] = {81, 39, 80, 6, 66, 63, 93, 4, 45, 76, 89, 90, 21, 84, 35, 88, 95, 17, 77, 64, 78, 2, 32, 44, 75, 27, 30, 58, 60, 28, 74, 72, 48, 41, 34, 51, 96, 97, 61, 33, 73, 91, 87, 68, 49, 83, 37, 16, 92, 53, 69, 85, 42, 7, 52, 38, 59, 56, 10, 71, 31, 15, 46, 22, 94, 86, 67, 300, 5, 62, 57, 65, 8, 9, 26, 40, 36, 1, 11, 13, 43, 20, 12, 24, 23, 98, 54, 82, 25, 14, 47, 29, 3, 99, 18, 55, 70, 19, 79, 50};

//     for (int q = 0; q < 300; q++)
//     {
//         std::cout << arr[q] << ", ";
//     }
// }

// -------------------------------------------------------------------------------------- //
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Selection Sort");
    sf::CircleShape shape(300.f);
    shape.setFillColor(sf::Color::Black);

    //Algorithm
    int minss_index;
    int minss;
    int tempy;
    std::vector<int> arr = {63, 274, 216, 293, 65, 68, 284, 231, 234, 239, 183, 288, 300, 189, 32, 217, 59, 275, 181, 3, 44, 203, 94, 285, 60, 78,
                            226, 229, 155, 290, 120, 287, 132, 241,
                            202, 193, 299, 36, 242, 102, 223, 296, 72, 47, 253, 300, 86, 46, 184, 125, 249,
                            240, 24, 81, 271, 136, 259, 210, 95, 218, 9, 144, 110, 54, 106, 62, 283, 192, 7, 153, 165, 208, 145, 295, 169, 268, 221, 294, 8, 277, 224, 17, 30, 131, 70, 298, 74, 13, 262, 278, 123, 158, 270, 122, 48, 6, 265, 199, 244, 114, 175, 292, 133, 250, 185, 273, 167, 168, 11, 211, 170,
                            246, 233, 64, 190, 19, 207, 16, 232, 129, 87, 92, 152, 177, 117, 191, 178, 261,
                            200, 247, 115, 71, 89, 160, 35, 276, 20, 254, 112, 43, 245, 40, 124, 260, 97, 149, 220, 45, 151, 130, 198, 138, 174, 282, 61, 137, 116, 171, 4, 281, 10, 126, 228, 186, 99, 12, 37, 188, 297, 172, 248,
                            31, 93, 91, 157, 206, 23, 163, 173, 235, 286, 195, 255, 28, 52, 82, 50, 26, 25,
                            141, 196, 263, 58, 146, 49, 77, 29, 258, 209, 147, 42, 98, 238, 84, 104, 257, 291, 269, 222, 135, 38, 109, 88, 101, 14,
                            140, 236, 111, 182, 256, 230, 215, 67, 1, 2, 266, 280, 75, 139, 197, 194, 41, 27, 201, 34, 53, 187, 161, 90, 57, 85, 252, 162, 15, 159, 214, 118, 105, 154, 166, 18, 103, 212, 237, 76, 156, 264, 127, 150, 179, 213, 225, 148, 272, 108, 119, 56, 21, 243, 176, 22, 128, 267, 39, 205,
                            180, 289, 66, 107, 219, 113, 279, 121, 96, 143, 33, 73, 5, 80, 69, 55, 164, 142, 51, 251, 134, 83, 227, 204, 79};
    std::vector<std::vector<int>> states = {};
    states.push_back(arr);
    std::vector<int> state = states.back();
    std::vector<int> ssstate = arr;
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

        for (int x = 0; x < 300; x++)
        {
            minss = arr[x];
            minss_index = x;
            for (int y = x; y < 300; y++)
            {
                if (arr[y] < minss)
                {
                    minss = arr[y];
                    minss_index = y;
                }
            }
            tempy = arr[x];
            arr[x] = minss;
            arr[minss_index] = tempy;
            // states.push_back(state);
            window.clear(sf::Color::Green);
            for (int i = 0; i < 300; i++)
            {
                sf::Vertex line[] =
                    {
                        sf::Vertex(sf::Vector2f(40 + 2 * i, 400 - arr[i])),
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
            window.setFramerateLimit(30);
            window.display();
        }
        window.setMouseCursorVisible(true);
        window.close();
    }
    return 0;
}
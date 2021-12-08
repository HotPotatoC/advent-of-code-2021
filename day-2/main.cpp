#include <iostream>
#include <vector>
#include <string>

auto part_one(std::vector<std::pair<std::string, int>> &directions)
{
    int horizontal_position = 0;
    int depth = 0;
    for (auto &direction : directions)
    {
        if (direction.first == "forward")
            horizontal_position += direction.second;

        if (direction.first == "down")
            depth += direction.second;

        if (direction.first == "up")
            depth -= direction.second;
    }

    return horizontal_position * depth;
}

auto part_two(std::vector<std::pair<std::string, int>> &directions)
{
    int horizontal_position = 0;
    int depth = 0;
    int aim = 0;
    for (auto &direction : directions)
    {
        if (direction.first == "forward")
        {
            horizontal_position += direction.second;
            depth += direction.second * aim;
        }

        if (direction.first == "down")
            aim += direction.second;

        if (direction.first == "up")
            aim -= direction.second;
    }

    return horizontal_position * depth;
}

int main()
{
    std::vector<std::pair<std::string, int>> directions;
    std::string direction;
    int amount;

    while (std::cin >> direction >> amount)
        directions.push_back(make_pair(direction, amount));

    std::cout << "Part one: " << part_one(directions) << std::endl;
    std::cout << "Part two: " << part_two(directions) << std::endl;

    return 0;
}
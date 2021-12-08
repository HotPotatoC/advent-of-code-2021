#include <iostream>
#include <vector>
#include <algorithm>

auto part_one(const std::vector<int> &measurements)
{
    int count = 0;
    for (std::size_t i = 1; i < measurements.size(); i++)
        if (measurements[i] > measurements[i - 1])
            count++;

    return count;
}

auto part_two(const std::vector<int> &measurements)
{
    int count = 0;
    int current_sum = measurements[0] + measurements[1] + measurements[2];
    int prev_sum = current_sum;

    for (std::size_t i = 1; i <= measurements.size() - 3; i++)
    {
        if ((current_sum += measurements[i + 2] - measurements[i - 1]) > prev_sum)
            count++;
        prev_sum = current_sum;
    }

    return count;
}

int main()
{
    std::vector<int> measurements;

    int a;
    while (std::cin >> a)
        measurements.push_back(a);

    std::cout << "Part one: " << part_one(measurements) << std::endl;
    std::cout << "Part two: " << part_two(measurements) << std::endl;

    return 0;
}
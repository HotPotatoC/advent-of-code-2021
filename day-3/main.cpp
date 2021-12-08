#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

auto part_one(const std::vector<std::string> &inputs)
{
    std::string gamma_rate;
    std::string epsilon_rate;

    for (std::size_t i = 0; i < inputs[0].size(); i++)
    {
        int zeroes_count = 0;
        int ones_count = 0;
        for (std::size_t j = 0; j < inputs.size(); j++)
        {
            if (inputs[j][i] == '0')
                zeroes_count++;
            if (inputs[j][i] == '1')
                ones_count++;
        }

        if (zeroes_count > ones_count)
        {
            gamma_rate.append("0");
            epsilon_rate.append("1");
        }

        if (zeroes_count < ones_count)
        {
            gamma_rate.append("1");
            epsilon_rate.append("0");
        }
    }

    return std::bitset<64>(gamma_rate).to_ullong() * std::bitset<64>(epsilon_rate).to_ullong();
}

auto part_two(const std::vector<std::string> &inputs) {}

int main()
{
    std::vector<std::string> inputs;
    std::string binary;

    while (std::cin >> binary)
        inputs.push_back(binary);

    std::cout << "Part one: " << part_one(inputs) << std::endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

std::vector<int> get_values(std::string fpath)
{
    std::vector<int> vals;
    std::string line;

    std::ifstream infile(fpath);
    while (getline(infile, line))
    {
        vals.push_back(atoi(line.c_str()));
    }
    infile.close();

    return vals;
}

int calculate_fuel(int input)
{
    int value = floor(input / 3) - 2;
    //std::cout << input << " -> " << value << "\n";
    return value;
}

void part1()
{
    auto values = get_values("data/day1part1.txt");
    int sum = 0;
    for (auto v : values)
    {
        sum += calculate_fuel(v);
    }
    std::cout << "Part 1: " << sum << std::endl;
}

void part2()
{
    auto values = get_values("data/day1part1.txt");
    int sum = 0;
    for (auto v : values)
    {
        auto fuel = calculate_fuel(v);
        sum += calculate_fuel(v);
        while (fuel > 0)
        {
            fuel = calculate_fuel(fuel);
            if (fuel > 0)
            {
                sum += fuel;
            }
        }
    }
    std::cout << "Part 2: " << sum << std::endl;
}

int main()
{
    part1();
    part2();
}

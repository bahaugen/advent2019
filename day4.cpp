#include <iostream>
#include <vector>

std::vector<int> get_digits(const int input)
{
    std::vector<int> digits;
    auto input_string = std::to_string(input);
    //std::cout << input_string << std::endl;
    for (size_t i = 0; i < input_string.size(); i++)
    {
        digits.push_back(input_string[i] - '0');
    }
    return digits;
}

bool adjacent_matches(std::vector<int> digits)
{
    for (size_t i = 0; i < digits.size() - 1; i++)
    {
        if (digits[i] == digits[i + 1])
        {
            return true;
        }
    }
    return false;
}

bool monotonically_increasing(std::vector<int> digits)
{
    for (size_t i = 0; i < digits.size() - 1; i++)
    {
        if (digits[i + 1] < digits[i])
        {
            return false;
        }
    }
    return true;
}

bool double_match(std::vector<int> digits)
{
    if ((digits[0] == digits[1]) && (digits[1] != digits[2]))
    {
        return true;
    }
    if ((digits[5] == digits[4]) && (digits[4] != digits[3]))
    {
        return true;
    }
    for (size_t i = 1; i < digits.size() - 1; i++)
    {
        if ((digits[i] != digits[i - 1]) && (digits[i] == digits[i + 1]) && (digits[i + 1] != digits[i + 2]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int count = 0;
    for (auto i = 123257; i <= 647015; i++)
    {
        auto digits = get_digits(i);
        if (monotonically_increasing(digits) && adjacent_matches(digits))
        {
            count++;
        }
    }
    std::cout << "Part 1 Total Password Count: " << count << std::endl;

    count = 0;
    for (auto i = 123257; i <= 647015; i++)
    {
        auto digits = get_digits(i);
        if (monotonically_increasing(digits) && double_match(digits))
        {
            count++;
        }
    }
    std::cout << "Part 2 Total Password Count: " << count << std::endl;
}
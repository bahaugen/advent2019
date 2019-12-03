#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

struct point
{
    int x, y;
    point(int x_in, int y_in)
    {
        x = x_in;
        y = y_in;
    }

    point get_right()
    {
        return point(x + 1, y);
    };
    point get_left()
    {
        return point(x - 1, y);
    };
    point get_up()
    {
        return point(x, y + 1);
    };
    point get_down()
    {
        return point(x, y - 1);
    };
    std::string to_string()
    {
        return "(x=" + std::to_string(x) + ",y=" + std::to_string(y) + ")";
    }
    bool operator==(const point &other)
    {
        if (x == other.x && y == other.y)
        {
            return true;
        }
        return false;
    }
};

std::vector<std::string> split_string(const std::string &str, const char sep)
{
    std::vector<std::string> parts;
    std::stringstream instring(str);
    std::string part;
    while (std::getline(instring, part, sep))
    {
        parts.push_back(part);
    }
    return parts;
}

std::vector<std::string> read_file(const std::string fname)
{
    std::vector<std::string> lines;
    std::ifstream infile(fname);
    std::string line;
    while (std::getline(infile, line))
    {
        lines.push_back(line);
    }
    return lines;
}

std::map<std::string, int> get_coords(std::vector<std::string> instructions)
{

    point current(0, 0);
    std::map<std::string, int> points;
    int time = 0;
    points.insert({current.to_string(), time});
    for (auto instruction : instructions)
    {
        int count = std::atoi(instruction.substr(1).c_str());
        std::cout << current.to_string() << " " << instruction << std::endl;
        for (auto i = 0; i < count; i++)
        {
            time += 1;
            if (instruction.at(0) == 'R')
            {
                //std::cout << instruction << " R "
                //          << " " << count << std::endl;
                current = current.get_right();
                points.insert({current.to_string(), time});
            }
            else if (instruction.at(0) == 'L')
            {
                //std::cout << instruction << " L "
                //          << " " << count << std::endl;
                current = current.get_left();
                points.insert({current.to_string(), time});
            }
            else if (instruction.at(0) == 'U')
            {
                //std::cout << instruction << " U "
                //          << " " << count << std::endl;
                current = current.get_up();
                points.insert({current.to_string(), time});
            }
            else if (instruction.at(0) == 'D')
            {
                //std::cout << instruction << " D "
                //          << " " << count << std::endl;
                current = current.get_down();
                points.insert({current.to_string(), time});
            }
        }
    }
    return points;
}

int main()
{
    auto wires = read_file("data/day3.txt");
    auto wire1 = split_string(wires[0], ',');
    auto wire2 = split_string(wires[1], ',');
    auto w1points = get_coords(wire1);
    auto w2points = get_coords(wire2);
    std::cout << "Intersections:" << std::endl;
    for (auto p : w1points)
    {
        if (w2points.find(p.first) != w2points.end())
        {
            std::cout << p.first << " "
                      << w1points[p.first] << " "
                      << w2points[p.first] << " "
                      << w1points[p.first] + w2points[p.first] << " "
                      << std::endl;
        }
    }
}
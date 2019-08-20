/*
ID: zjjc123
TASK: BucketBrigade
LANG: C++                 
*/

/*
Solution:
    Check to see if the buckets is between the lake and barn
    if it is add 2 to distance
 */
#include <fstream>
#include <iostream>
#include <cmath>

struct Vector2
{
    int x, y;
};

std::ostream &operator<<(std::ostream &os, const Vector2 v2)
{
    os << v2.x << ", " << v2.y;
    return os;
}

int FindDistance(Vector2 Barn, Vector2 Rock, Vector2 Lake)
{
    if (Rock.x == Barn.x && Rock.x == Lake.x)
    {
        std::cout << "X line up" << std::endl;
        if ((Rock.y < Barn.y && Rock.y > Lake.y) || (Rock.y > Barn.y && Rock.y < Lake.y))
        {
            std::cout << "Y axis Rock between lake and barn" << std::endl;
            return std::abs(Barn.x - Lake.x) + std::abs(Barn.y - Lake.y) + 1;
        }
        else
        {
            std::cout << "Y axis Rock NOT between lake and barn" << std::endl;
            return std::abs(Barn.x - Lake.x) + std::abs(Barn.y - Lake.y) - 1;
        }
    }
    else if (Rock.y == Barn.y && Rock.y == Lake.y)
    {
        std::cout << "Y line up" << std::endl;
        if ((Rock.x < Barn.x && Rock.x > Lake.x) || (Rock.x > Barn.x && Rock.x < Lake.x))
        {
            std::cout << "X axis Rock between lake and barn" << std::endl;
            return std::abs(Barn.x - Lake.x) + std::abs(Barn.y - Lake.y) + 1;
        }
        else
        {
            std::cout << "X axis Rock NOT between lake and barn" << std::endl;
            return std::abs(Barn.x - Lake.x) + std::abs(Barn.y - Lake.y) - 1;
        }
    }
    else
    {
        std::cout << "X and Y don't line up" << std::endl;
        return std::abs(Barn.x - Lake.x) + std::abs(Barn.y - Lake.y) - 1;
    }
}

int main()
{
    std::ifstream fin("buckets.in");

    Vector2 Barn;
    Vector2 Rock;
    Vector2 Lake;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char block;
            fin >> block;
            if (block == 'B')
            {
                Barn.x = i;
                Barn.y = j;
            }
            if (block == 'R')
            {
                Rock.x = i;
                Rock.y = j;
            }
            if (block == 'L')
            {
                Lake.x = i;
                Lake.y = j;
            }
        }
    }
    int distance = FindDistance(Barn, Rock, Lake);

    std::cout << "Barn: " << Barn << std::endl;
    std::cout << "Rock: " << Rock << std::endl;
    std::cout << "Lake: " << Lake << std::endl;

    std::cout << "Distance: " << distance << std::endl;

    std::ofstream fout("buckets.out");
    fout << distance;
}
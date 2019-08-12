/*
ID: zjjc123
TASK: The Great Revegetation
LANG: C++                 
*/

/*
Keep adding 1 to field until everything is different
 */

#include <fstream>
#include <iostream>

bool isCorrect(int cows[][2], int fields[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (fields[cows[i][0] - 1] == fields[cows[i][1] - 1])
            return false;
    }
    return true;
}

int main()
{
    std::ifstream fin("revegetate.in");
    int n;
    int m;

    fin >> n >> m;

    std::cout << "Fields: "  << n << std::endl;
    std::cout << "Cows: " << m << std::endl;

    int cows [m][2];
    int fields[n];

    for (int i = 0; i < m; i++)
    {
        fin >> cows[i][0] >> cows[i][1];
        std::cout << "Cow "  << i << std::endl;
        std::cout << cows[i][0] << std::endl;
        std::cout << cows[i][1] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        fields[i] = 1;
    }

    while (!isCorrect(cows, fields, m))
    {
        for (int i = 0; i < m; i++)
        {
            if (fields[cows[i][0] - 1] == fields[cows[i][1] - 1])
            {
                fields[cows[i][1] - 1]++;
                std::cout << "Add 1 to field "  << cows[i][1] << std::endl;
            }
        }
    }

    std::ofstream fout("revegetate.out");

    for (int i = 0; i < n; i++)
    {
        fout << fields[i];
        std::cout << fields[i];
    }
}

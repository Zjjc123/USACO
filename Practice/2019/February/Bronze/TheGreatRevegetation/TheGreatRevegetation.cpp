/*
ID: zjjc123
TASK: The Great Revegetation
LANG: C++                 
*/

/*
Solution: Go from left to right, check every connection and eliminate unavaiable choices.
Choose the smallest one for each field.s
 */

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream fin("revegetate.in");
    int n;
    int m;

    fin >> n >> m;

    std::cout << "Fields: " << n << std::endl;
    std::cout << "Cows: " << m << std::endl;

    int cows[m][2];
    int fields[n];

    for (int i = 0; i < m; i++)
    {
        fin >> cows[i][0] >> cows[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        fields[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int possible[5] = {0, 1, 2, 3, 4};
        for (int j = 0; j < m; j++)
        {
            if (cows[j][0] - 1 == i)
            {
                if (cows[j][1] - 1 < i)
                {
                    possible[fields[cows[j][1] - 1]] = 0;
                }
            }
            if (cows[j][1] - 1 == i)
            {
                if (cows[j][0] - 1 < i)
                {
                    possible[fields[cows[j][0] - 1]] = 0;
                }
            }
        }
        for (int j = 1; j < 5; j++)
        {
            if (possible[j] != 0)
            {
                fields[i] = possible[j];
                break;
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

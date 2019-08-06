/*
ID: zjjc123
TASK: Shell Game
LANG: C++                 
*/

/*
Solution: No Idea --> gonna try to brute force

 */

#include <fstream>

int main()
{
    std::ifstream fin("shell.in");
    int swaps;
    fin >> swaps;
    int game[swaps][3];

    for (int i = 0; i < swaps; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fin >> game[i][j];
        }
    }

    int startOne = 0;
    int startTwo = 0;
    int startThree = 0;

    int now;

    // Start One
    now = 1;
    for (int i = 0; i < swaps; i++)
    {
        if (game[i][0] == now)
        {
            now = game[i][1];
        }
        else if (game[i][1] == now)
        {
            now = game[i][0];
        }
        if (game[i][2] == now)
        {
            startOne++;
        }
    }
    // Start Two
    now = 2;
    for (int i = 0; i < swaps; i++)
    {
        if (game[i][0] == now)
        {
            now = game[i][1];
        }
        else if (game[i][1] == now)
        {
            now = game[i][0];
        }
        if (game[i][2] == now)
        {
            startTwo++;
        }
    }
    // Start Three
    now = 3;
    for (int i = 0; i < swaps; i++)
    {
        if (game[i][0] == now)
        {
            now = game[i][1];
        }
        else if (game[i][1] == now)
        {
            now = game[i][0];
        }
        if (game[i][2] == now)
        {
            startThree++;
        }
    }
    std::ofstream fout("shell.out");
    fout << (std::max(std::max(startOne, startTwo), startThree)) << std::endl;

    return 0;
}
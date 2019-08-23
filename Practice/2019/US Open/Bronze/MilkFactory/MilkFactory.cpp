/*
ID: zjjc123
TASK: Milk Factory
LANG: C++                 
*/

/*
Solution:
    Practicing BFS (there is an easier solution im dumb dumb)
 */

#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream fin("factory.in");
    int station;
    fin >> station;

    int solution = -1;
    int con[station - 1][2];

    for (int i = 0; i < station - 1; i++)
    {
        fin >> con[i][0] >> con[i][1];
    }

    // For each station i
    for (int i = 1; i < station + 1; i++)
    {
        // BFS queue
        std::vector<int> queue;
        // For each connection j
        for (int j = 0; j < station - 1; j++)
        {
            // If the connection starts at j --> enqueue destination (swap)
            if (con[j][1] == i)
            {
                queue.push_back(con[j][0]);
            }
        }
        int stationsPossible = 1;    
        // While there are still stations in queue
        while (queue.size() > 0)
        {
            // get the first number and set it as start
            int root = queue[0];
            queue.erase(queue.begin());

            stationsPossible++;
            // For each connection j
            for (int j = 0; j < station - 1; j++)
            {
                // If the connection starts at j --> enqueue destination (swap)
                if (con[j][1] == root)
                {
                    queue.push_back(con[j][0]);
                }
            }
        } 
        // If all station can be reached --> solution!!
        if (stationsPossible == station) 
        {
            solution = i;
            break;
        }
    }
    std::ofstream fout("factory.out");
    fout << solution;
}


/*
ID: zjjc123
TASK: Convention
LANG: C++                 
*/

/*
Solution:
    Largest consecutive-Cvalue difference?
    But can assign bus not full if saves time and have more bus
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using std::cout; using std::endl;

    int N, M, C;
    std::ifstream fin("TestData/2.in");
    fin >> N >> M >> C;

    // Put all times into a vector
    std::vector<int> times;
    times.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        fin >> temp;
        times.push_back(temp);
    }

    // Sort
    std::sort(times.begin(), times.end());

    // Store the time for each bus to see where to optimize
    std::vector<int> maxTimes;
    maxTimes.reserve(M);

    // For every bus, find the wait time
    int max = 0;
    for (int i = 0; i < N; i+=C)
    {
        // Largest and smallest of the bus
        int maxBustime = times[i+C-1] - times[i];

        maxTimes.push_back(maxBustime);

        if (maxBustime > max)
            max = maxBustime;
    }

    // Go through the max time to find optimization
    // If a free bus could be send early to reduce time then do it

    std::ofstream fout("convention.out");
    cout << max << endl;
    fout << max;
}

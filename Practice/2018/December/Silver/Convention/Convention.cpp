/*
ID: zjjc123
TASK: Convention
LANG: C++                 
*/

/*
Solution:
    Largest consecutive-Cvalue difference?
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using std::cout; using std::endl;

    int N, M, C;
    std::ifstream fin("convention.in");
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

    // For every bus, find the wait time
    int max = 0;

    for (int i = 0; i < N; i+=C)
    {
        // Largest and smallest of the bus
        int maxBustime = times[i+C-1] - times[i];
        cout << times[i+C-1] << " - " << times[i] << endl;
        if (maxBustime > max)
            max = maxBustime;
    }

    std::ofstream fout("convention.out");
    cout << max << endl;
    fout << max;
}

/*
ID: zjjc123
TASK: Convention
LANG: C++                 
*/

/*
Solution:
    Use a target value to check if arrangement would work. 
    If it doesnt, then anything below it wouldn't
    narrow the target value by using binary search.
    Check if value works by keep placing cows in bus until it exceeds time and see if busses run out or not.
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;

bool PossibleCheck(int N, int M, int C, int target, const std::vector<int>& times)
{
    int used = 1;
    std::vector<int> cowsOnBus;

    cowsOnBus.push_back(times[0]);
    //cout << "add " << times[0] << " to bus " << used << endl;

    // For each cows
    for (int i = 1; i < N; i++)
    {
        // If exceed target then make a new bus, else keep adding to the same bus
        cowsOnBus.push_back(times[i]);
        //cout << "add " << times[i] << " to bus " << (used) << endl;
        // If size exceed --> add to next one 
        if ((cowsOnBus[cowsOnBus.size()-1] - cowsOnBus[0]) > target)
        {
            used++;
            cowsOnBus.clear();
            //cout << "new bus " << used << endl;
            cowsOnBus.push_back(times[i]);
            //cout << "add " << times[i] << " to bus " << (used) << endl;
        }
        // If capacity is reached but not size --> clear car
        else if (cowsOnBus.size() == C)
        {
            used++;
            cowsOnBus.clear();
            //cout << "new bus " << used << endl;
        }

    }
    // If using more bus then not possible
    //cout << "used: " << used << " busses: " << M << endl;
    if (used > M && !(cowsOnBus.size() == 0))
    {
        //cout << target << " is not a solution" << endl;
        return false;
    }
    else
        return true;
}


int main()
{
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
    const int maxCowTime = times[N-1];
    cout << "array size: " << maxCowTime << endl;
    // store on heap because stack might not be big enough

    int l = 0; int r = maxCowTime - 1;
    int max;
    while(l <= r)
    {
        int m = (l + r) / 2;
        cout << "checking: " << m << endl;
        cout << "l: " << l << " r: " << r << endl;
        //cout << "possible: " << PossibleCheck(N, M, C, possible[m], times) << endl;
        if (PossibleCheck(N, M, C, m, times))
        {
            cout << m << " is possible" << endl;
            max = m;
            r = m - 1;
        }
        else
        {
            cout << m << " is not possible" << endl;
            l = m + 1;
        }
    }

    std::ofstream fout("convention.out");
    cout << max << endl;
    fout << max;
}

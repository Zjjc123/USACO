/**
ID: zjjc123
TASK: Swapity Swapity Swap
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib> 
#include <iostream>    
#include <algorithm>   
#include <vector>       

template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    return (v1.size() == v2.size() &&
            std::equal(v1.begin(), v1.end(), v2.begin()));
}

int main()
{
    std::ifstream fin("swap.in");
    std::ofstream fout("swap.out");

    std::vector<int> cows;
    std::vector<int> comp;

    int N;
    fin >> N;

    int M;
    fin >> M;

    int K;
    fin >> K;
    
    int * left = new int[M];
    int * right = new int[M];
    for (int i = 0; i < M; i++)
    {
        fin >> left[i] >> right[i];
    }

    for (int i = 1; i <= N; i++) 
    {
        cows.push_back(i);
        comp.push_back(i);
    }

    bool breakearly = false;
    for (int i = 0; i < K; i++)
    {
        for (int i = 0; i < M; i++)
        {
            std::reverse(cows.begin() + left[i] - 1, cows.begin() + right[i]);
        }
        if (isEqual(cows, comp))
        {
            K = K % (i + 1);
            breakearly = true;
            break;
        }
    }
    if (breakearly)
    {
        for (int i = 0; i < M; i++)
        {
            std::reverse(cows.begin() + left[i] - 1, cows.begin() + right[i]);
        }
    }

    for (int i = 0; i < N; i++) 
        fout << cows.at(i) << std::endl;
}

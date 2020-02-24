/**
ID: zjjc123
TASK: Swapity Swap
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib> 
#include <iostream>    
#include <algorithm>   
#include <vector>       

int main()
{
    std::ifstream fin("swap.in");
    std::ofstream fout("swap.out");

    std::vector<int> cows;

    int N;
    fin >> N;
    int K;
    fin >> K;

    int a1; int a2;
    fin >> a1 >> a2;

    int b1; int b2;
    fin >> b1 >> b2;

    for (int i = 1; i <= N; i++) 
        cows.push_back(i);

    for (int i = 0; i < K; i++)
    {
        std::reverse(cows.begin() + a1 - 1, cows.begin() + a2);
        std::reverse(cows.begin() + b1 - 1, cows.begin() + b2);
    }
    for (int i = 0; i < N; i++) 
        fout << cows.at(i) << std::endl;
}
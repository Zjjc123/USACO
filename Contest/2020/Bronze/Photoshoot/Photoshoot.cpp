/*
ID: zjjc123
TASK: Photoshoot
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::ifstream fin("photo.in");
    std::ofstream fout("photo.out");
    
    int N;
    fin >> N;

    int * permutation = new int[N];
    int * checker = new int[N];

    for (int i = 0; i < N; i++)
    {
        fin >> permutation[i];
        checker[i] = 0;
    }

    int * newP = new int[N-1];

    bool correct = true;


    for (int i = 1; i < permutation[0]; i++)
    {
        correct = true;
        for (int j = 0; j < N; j++)
        {
            checker[j] = 0;
        }
        newP[0] = i;
        std::cout << newP[0] << std::endl;

        for (int j = 1; j < N; j++)
        {
            newP[j] = permutation[j - 1] - newP[j - 1];
            std::cout << newP[j] << std::endl;
        }

        for (int j = 0; j < N; j++)
        {
            if (newP[j] < 1 || newP[j] > N)
            {
                std::cout << newP[j] << " too low or too high" << std::endl;
                correct = false;
                break;
            }
            else if (checker[newP[j] - 1] == 0)
            {
                std::cout << newP[j] << " added" << std::endl;
                checker[newP[j] - 1] = 1;
            }
            else
            {
                std::cout << newP[j] << " is the same exit" << std::endl;
                correct = false;
                break;
            }
        }
        if (correct)
        {
            std::cout << "Correct" << std::endl;
            break;
        }
    }
    fout << newP[0];
    for (int i = 1; i < N; i++)
    {
        fout << " " << newP[i];
    }
}
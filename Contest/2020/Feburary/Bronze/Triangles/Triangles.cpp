/**
ID: zjjc123
TASK: Triangles
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib> 

int main()
{
    std::ifstream fin("triangles.in");
    std::ofstream fout("triangles.out");

    int N;
    fin >> N;
    int * x = new int[N];
    int * y = new int[N];

    int maxArea = 0;
    for (int i = 0; i < N; i++)
    {
        fin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++)
    {
        int xPoint = x[i];
        int yPoint = y[i];

        int maxX = 0;
        int maxY = 0;
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                if (abs(x[j] - xPoint) > maxX && y[i] == y[j])
                    maxX = abs(x[j] - xPoint);
                if (abs(y[j] - yPoint) > maxY && x[i] == x[j])
                    maxY = abs(y[j] - yPoint);
            }
        }

        int thisMaxArea = maxX * maxY;
        if (thisMaxArea > maxArea)
            maxArea = thisMaxArea;
    }
    fout << maxArea;
}
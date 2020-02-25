/**
ID: zjjc123
TASK: Triangles
LANG: C++                 
*/

#include <fstream>
#include <unordered_set> 
#include <utility> 
#include <iostream>
#include <cstdlib> 
#include <math.h>
#include <functional>

using namespace std; 

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

int main()
{
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int N;
    fin >> N;
    
    unordered_set<pair<int, int>, pair_hash> points;

    int sum = 0;
    int max = (int)pow(10, 9) + 7;

    for (int i = 0; i < N; i++)
    {
        int x; 
        int y;
        fin >> x >> y;

        for (const auto& element: points)
        {
            pair<int, int> p1 = make_pair(element.first, y);
            pair<int, int> p2 = make_pair(x, element.second);

            if (points.find(p1) != points.end())
            {
                int add = (p1.second - element.second) * (p1.first - x);
                sum += abs(add);
            }

            if (points.find(p2) != points.end())
            {
                int add = (p2.first - element.first) * (p2.second - y);
                sum += abs(add);
            }

            sum = sum % max;
        }        
        points.insert(make_pair(x, y));
    }

    fout << sum;
}
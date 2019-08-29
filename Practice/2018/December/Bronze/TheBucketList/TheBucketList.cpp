/*
ID: zjjc123
TASK: The Bucket List
LANG: C++                 
*/

/*
Solution:
 */

#include <fstream>
#include <iostream>

/* Solution:
    Brute Force?
*/

struct cow
{
    int start, end, buckets;
    bool isMilking = false;
};

int main()
{
    std::ifstream fin("blist.in");
    int n;
    fin >> n;

    int maxTime = 0;
    int buckets = 0;

    int maxBuckets = 0;
    cow cows[n];
    for (int i = 0; i < n; i++)
    {
        fin >> cows[i].start >> cows[i].end >> cows[i].buckets;
        if (cows[i].end > maxTime)
            maxTime = cows[i].end;
    }  

    for (int i = 1; i < maxTime; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cows[j].start == i)
                buckets += cows[j].buckets;
            if (cows[j].end == i)
                buckets -= cows[j].buckets;
        }
        if (buckets > maxBuckets)
            maxBuckets = buckets;
    }

    std::ofstream fout("blist.out");
    fout << maxBuckets;


}

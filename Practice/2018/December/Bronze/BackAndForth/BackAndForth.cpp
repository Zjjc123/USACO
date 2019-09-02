/*
ID: zjjc123
TASK: Back And Forth
LANG: C++                 
*/

/*
Solution:
    Brute force?
 */
#include <fstream>
#include <iostream>
#include <vector>

int possible[2000];

void friday(int barn1, std::vector<int> barn1Buckets, std::vector<int> barn2Buckets)
{
    for (int i = 0; i < barn2Buckets.size(); i++)
    {
        //std::cout << "Friday Bucket: " << i << std::endl;
        int b = barn2Buckets[i];
        possible[barn1 + b] = 1;
    }
}
void thursday(int barn1, std::vector<int> barn1Buckets, std::vector<int> barn2Buckets)
{
    for (int i = 0; i < barn1Buckets.size(); i++)
    {
        //std::cout << "Thursday Bucket: " << i << std::endl;
        int b = barn1Buckets[i];
        std::vector<int> barn2New = barn2Buckets; 
        barn2New.push_back(b);
        std::vector<int> barn1New = barn1Buckets; 
        barn1New.erase(barn1New.begin() + i);
        friday(barn1 - b, barn1New, barn2New);
    }
}
void wednesday(int barn1, std::vector<int> barn1Buckets, std::vector<int> barn2Buckets)
{
    for (int i = 0; i < barn2Buckets.size(); i++)
    {
        //std::cout << "Wednesday Bucket: " << i << std::endl;
        int b = barn2Buckets[i];
        std::vector<int> barn1New = barn1Buckets; 
        barn1New.push_back(b);
        std::vector<int> barn2New = barn2Buckets; 
        barn2New.erase(barn2New.begin() + i);
        thursday(barn1 + b, barn1New, barn2New);
    }
}
void tuesday(int barn1, std::vector<int> barn1Buckets, std::vector<int> barn2Buckets)
{
    for (int i = 0; i < barn1Buckets.size(); i++)
    {
        //std::cout << "Tuesday Bucket: " << barn1Buckets[i] << std::endl;
        int b = barn1Buckets[i];
        std::vector<int> barn2New = barn2Buckets; 
        barn2New.push_back(b);
        std::vector<int> barn1New = barn1Buckets; 
        barn1New.erase(barn1New.begin() + i);
        wednesday(barn1 - b, barn1New, barn2New);
    }
}

int main()
{
    std::ifstream fin("backforth.in");

    std::vector<int> barn1(10);
    std::vector<int> barn2(10);

    for (int i = 0; i < 10; i++)
    {
        fin >> barn1[i];
    }

    for (int i = 0; i < 10; i++)
    {
        fin >> barn2[i];
    }

    tuesday(1000, barn1, barn2);

    int answer = 0;
    for (int i = 0; i < 2000; i++)
    {
        answer+=possible[i];
    }
    std::cout << answer << std::endl;
    std::ofstream fout("backforth.out");
    fout << answer;
}
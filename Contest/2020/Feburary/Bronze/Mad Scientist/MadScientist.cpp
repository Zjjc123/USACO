/**
ID: zjjc123
TASK: Mad Scientist
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib> 

int main()
{
    std::ifstream fin("breedflip.in");
    std::ofstream fout("breedflip.out");

    int N;
    fin >> N;

    int count = 0;

    std::string a;
    fin >> a;
    std::string b;
    fin >> b;

    bool consecutive = false;

    for (int i = 0; i < N; i++)
    {
        char aCow = a.at(i);
        char bCow = b.at(i);

        std::cout << aCow << std::endl;
        if (aCow != bCow)
        {
            if (!consecutive)
            {
                consecutive = true;
                count++;
            }
            
        }
        else
        {
            consecutive = false;
        }
        
    }
    
    fout << count;
}
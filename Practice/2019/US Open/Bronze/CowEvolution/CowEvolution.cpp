/*
ID: zjjc123
TASK: Cow Evolution
LANG: C++                 
*/

/*
Solution:
    Bad Case:
        A
        B
        AB
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

bool contains(std::vector<std::string *> &v, std::string *x)
{
    for (int i = 0; i < v.size(); i++)
    {
        //std::cout << (((*v[i]).compare(*x)) == 0) << std::endl;
        if (((*v[i]).compare(*x)) == 0)
        {
            //std::cout << "contains!" << std::endl;
            return true;
        }
    }
    return false;
}


int main()
{
    std::ifstream fin("evolution.in");
    int cows;
    fin >> cows;

    bool proper = true;

    std::vector<std::string *> evolution[cows];

    for (int i = 0; i < cows; i++)
    {
        int features;
        fin >> features;
        for (int j = 0; j < features; j++)
        {
            std::string * feature = new std::string;
            fin >> (*feature);
            evolution[i].push_back(feature);
        }
    }
    // For each cow
    for (int i = 0; i < cows; i++)
    {
        // If there is more than 1 evolution
        if (evolution[i].size() > 1)
        {
            // Compare every pair of evolution of the cow
            for (int j = 0; j < evolution[i].size(); j++)
            {
                for (int k = 1; k < evolution[i].size(); k++)
                {
                    if (j != k)
                    {
                        std::cout << "Checking " << i << " cow and " << *evolution[i][j] << " " << *evolution[i][k] << " pair" << std::endl;
                        // Check for A, B, AB situation
                        for (int l = 0; l < cows; l++)
                        {
                            for (int m = 0; m < cows; m++){
                                // If contains one of the element of the pair but not the other
                                if (contains(evolution[l], evolution[i][j]) && !contains(evolution[m], evolution[i][j]))
                                {   
                                    if (contains(evolution[m], evolution[i][k]) && !contains(evolution[l], evolution[i][k]))
                                    {
                                        std::cout << l << " has " << *evolution[i][j] << " but " << m << " doesn't" << std::endl;
                                        std::cout << m << " has " << *evolution[i][k] << " but " << l << " doesn't" << std::endl;
                                        proper = false;
                                        goto output;
                                    }
                                }

                                if (contains(evolution[l], evolution[i][k]) && !contains(evolution[m], evolution[i][k]))
                                {
                                    if (contains(evolution[m], evolution[i][j]) && !contains(evolution[l], evolution[i][j]))
                                    {
                                        std::cout << l << " has " << *evolution[i][k] << " but " << m << " doesn't" << std::endl;
                                        std::cout << m << " has " << *evolution[i][j] << " but " << l << " doesn't" << std::endl;
                                        proper = false;
                                        goto output;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    output: std::ofstream fout("evolution.out");
    if (proper)
    {
        fout << "yes";
        std::cout << "Yes!" << std::endl;
    }
    else
    {   
        fout << "no";
        std::cout << "No!" << std::endl;
    }
}


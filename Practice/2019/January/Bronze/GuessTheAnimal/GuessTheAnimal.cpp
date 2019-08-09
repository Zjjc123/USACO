/*
ID: zjjc123
TASK: Guess The Animal
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

int main()
{
    std::ifstream fin("TestData/2.in");

    int animals;
    fin >> animals;

    std::cout << "animals: " << animals << std::endl;

    std::map<std::string, int> traits;

    for (int i = 0; i < animals; i++)
    {
        std::string name;
        int numberOfTraits = 0;

        fin >> name;
        fin >> numberOfTraits;

        //std::cout << "number of traits: " << numberOfTraits << std::endl;

        for (int j = 0; j < numberOfTraits; j++)
        {
            std::string trait;
            fin >> trait;

            if (traits.count(trait))
            {
                traits[trait] = traits[trait] + 1;
                //std::cout << "trait " << trait << " add 1" << std::endl;
            } 
            else
            {
                traits.insert(std::pair<std::string, int>(trait, 1));
                //std::cout << "add new trait: " << trait << std::endl;
            }
            
        }
        
    }

    std::map<std::string, int>::iterator it;
    int count = 0;
    std::cout << "Finding Count" << std::endl;
    for (it = traits.begin(); it != traits.end(); it++)
    {
        std::cout << it -> first << " : " << it -> second << std::endl;

        if (it -> second > 1)
        {
            count++;
        }
    }

    count += 1;
    std::ofstream fout("guess.out");
    fout << count << std::endl;

    std::cout << "count: " << count << std::endl;


}
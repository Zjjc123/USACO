/*
ID: zjjc123
TASK: Guess The Animal
LANG: C++                 
*/

/*
Solution: To find the maximum number of guesses, its the most number of traits that is shared between two animal


 */
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

int main()
{
    std::ifstream fin("guess.in");

    int numAnimals;
    fin >> numAnimals;

    // Stores the traits of animals (array of vectors pointers of string)
    std::vector<std::string> * animals[numAnimals];

    for (int i = 0; i < numAnimals; i++)
    {
        std::string name;
        int numberOfTraits = 0;

        fin >> name;
        fin >> numberOfTraits;

        animals[i] = new std::vector<std::string>;
        for (int j = 0; j < numberOfTraits; j++)
        {
            std::string trait;
            fin >> trait;

            (*animals[i]).push_back(trait);

        }
    }

    int max = 0;

    // Comparing to find the max shared trait between two animals
    for (int i = 0; i < (numAnimals - 1); i++)
    {
        for (int j = i + 1; j < numAnimals; j++)
        {
            int temp = 0;
            for (int k = 0; k < (*animals[i]).size(); k++)
            {
                for (int l = 0; l < (*animals[j]).size(); l++)
                {
                    if ((*(animals[i]))[k] == (*(animals[j]))[l])
                    {
                        temp++;
                    }
                }
            }
            if (temp > max)
            {
                max = temp;
            }
        }
    }

    max++;

    std::ofstream fout("guess.out");
    fout << max << std::endl;
}
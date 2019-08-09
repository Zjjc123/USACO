/*
ID: zjjc123
TASK: Guess The Animal
LANG: C++                 
*/

/*
Solution: To find the maximum number of guesses, its the most number of traits that is shared in ONE animal


 */
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

int main()
{
    std::ifstream fin("TestData/2.in");

    int numAnimals;
    fin >> numAnimals;

    std::cout << "animals: " << numAnimals << std::endl;

    // Stores the frequency of traits
    // if frequency of traits is greater than 1 then it counts
    std::map<std::string, int> traits;

    // Stores the traits of animals (array of vectors of string)
    // to later compare to frequency dictionary
    std::vector<std::string> *animals[numAnimals];

    for (int i = 0; i < numAnimals; i++)
    {
        std::string name;
        int numberOfTraits = 0;

        fin >> name;
        fin >> numberOfTraits;

        //std::cout << "number of traits: " << numberOfTraits << std::endl;
        animals[i] = new std::vector<std::string>;
        for (int j = 0; j < numberOfTraits; j++)
        {
            std::string trait;
            fin >> trait;

            (*animals[i]).push_back(trait);

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

    int animalCountableTraits[numAnimals];

    std::map<std::string, int>::iterator it;

    std::cout << "Comparing Traits" << std::endl;
    for (int i = 0; i < numAnimals; i++)
    {
        animalCountableTraits[i] = 0;
        for (it = traits.begin(); it != traits.end(); it++)
        {
            if ((it->second) > 1)
            {
                std::cout << "Test trait： " << it->first << std::endl;
                //std::cout << it->first << " : " << it->second << std::endl;
                std::cout << "animal " << i << ": " << (*animals[i]).size() << " ";
                for (int j = 0; j < ((*animals[i]).size()); j++)
                {
                    std::cout << (*animals[i])[j] << ", ";
                    if ((*animals[i])[j] == (it->first))
                    {

                        animalCountableTraits[i]++;
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < numAnimals; i++)
    {
        std::cout << animalCountableTraits[i] << std::endl;
        if (animalCountableTraits[i] > count)
        {
            count = animalCountableTraits[i];
        }
    }

    count += 1;
    std::ofstream fout("guess.out");
    fout << count << std::endl;

    std::cout << "count: " << count << std::endl;
}
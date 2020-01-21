/*
ID: zjjc123
TASK: Word Processor
LANG: C++                 
*/

#include <fstream>
#include <string>

int main()
{
    std::ifstream fin("word.in");
    std::ofstream fout("word.out");
    
    int total;
    int lineCount;


    fin >> total;
    fin >> lineCount;


    int cCount = 0;
    bool firstTime = false;


    for (int i = 0; i < total; i++)
    {
        std::string word;
        fin >> word;

        if (firstTime)
        {
            if (cCount + word.length() <= lineCount)
            {
                fout << " " << word;
                cCount += word.length();
            }
            else
            {
                fout << std::endl << word;
                cCount = word.length();
            }
        }
        else
        {
            fout << word;
            firstTime = true;
            cCount = word.length();
        }
        
    }
}
/*
ID: zjjc123
TASK: Measuring Traffic
LANG: C++                 
*/

/*
Solution: A crap load of case work
 */

#include <fstream>
#include <iostream>
#include <string>

using String = std::string;

struct Sensor 
{
    String type;
    int min;
    int max;
};

int main()
{
    int eMin = 0;
    int eMax = 0;
    bool eNone = false;

    int bMin = 0;
    int bMax = 0;
    bool bNone = false;

    std::ifstream fin("traffic.in");
    int n;
    fin >> n;

    Sensor * data[n];

    for (int i = 0; i < n; i++)
    {
        Sensor * sen = new Sensor;
        String type;
        fin >> sen->type;
        fin >> sen->min >> sen->max;
        data[i] = sen;
    }

    for (int i = 0; i < n; i++)
    {
        if (data[i]->type == "none")
        {
            if (eNone == false)
            {
                eNone = true;
                eMin = data[i]->min;
                eMax = data[i]->max;
            }
            else
            {
                eMin = std::max(eMin, data[i]->min);
                eMax = std::min(eMax, data[i]->max);
            }
        } 
        else if (data[i]->type == "on")
        {
            eMin += data[i]->min;
            eMax += data[i]->max;
        }
        else
        {
            eMin -= data[i]->max;
            eMax -= data[i]->min;
        }
    }

    for (int i = (n - 1); i >= 0; i--)
    {
        if (data[i]->type == "none")
        {
            if (bNone == false)
            {
                bNone = true;
                bMin = data[i]->min;
                bMax = data[i]->max;
            }
            else
            {
                bMin = std::max(bMin, data[i]->min);
                bMax = std::min(bMax, data[i]->max);
            }
        } 
        else if (data[i]->type == "off")
        {
            bMin += data[i]->min;
            bMax += data[i]->max;
        }
        else
        {
            bMin -= data[i]->max;
            bMax -= data[i]->min;
        }
    }
    bMin = std::max(0, bMin);
    bMax = std::max(0, bMax);
    eMin = std::max(0, eMin);
    eMax = std::max(0, eMax);

    std::ofstream fout("traffic.out");

    fout << bMin << " " << bMax << std::endl;
    fout << eMin << " " << eMax << std::endl;

    std::cout << bMin << " " << bMax << std::endl;
    std::cout << eMin << " " << eMax << std::endl;
}
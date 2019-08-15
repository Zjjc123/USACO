/*
ID: zjjc123
TASK: Measuring Traffic
LANG: C++                 
*/

/*
Solution: Go from left to right, check every connection and eliminate unavaiable choices.
Choose the smallest one for each field.s
 */

#include <fstream>
#include <iostream>
#include <string>

using String = std::string;
/*
enum Ramp 
{
    On,
    Off,
    None
};

struct Sensor 
{
    Ramp type;
    int max;
    int min;
};
*/

int main()
{
    std::ifstream fin("TestData/1.in");
    int n;
    fin >> n;

    int bMin = 0;
    int bMax = 0;
    int bMinChange = 0;
    int bMaxChange = 0;
    bool bNone = false;

    int eMin = 0;
    int eMax = 0;
    bool eNone = false;
    for (int i = 0; i < n; i++)
    {   
        String type;
        fin >> type;

        if (type == "none")
        {
            if (bNone == false)
            {
                bNone = true;
                fin >> bMin >> bMax;
            }
            else
            {
                int bTempMin;
                int bTempMax;
                fin >> bTempMin >> bTempMax;
            }
        }
        else if (type == "on")
        {
            if (bNone == true)
            {
                break;
            }
            int bTempMin;
            int bTempMax;
            fin >> bTempMin >> bTempMax;

            bMinChange -= bTempMin;
            bMaxChange -= bTempMax;

        }
        else if (type == "off")
        {
            if (bNone == true)
            {
                break;
            }
            int bTempMin;
            int bTempMax;
            fin >> bTempMin >> bTempMax;

            bMinChange += bTempMin;
            bMaxChange += bTempMax;
        }
    }
        
    bMin += bMinChange;
    bMax += bMaxChange;

    bMin = std::max(0, bMin);
    bMax = std::max(0, bMax);

}
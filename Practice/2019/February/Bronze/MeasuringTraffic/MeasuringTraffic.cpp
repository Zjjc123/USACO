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
    std::ifstream fin("traffic.in");
    int n;
    fin >> n;

    int bMin = 0;
    int bMax = 0;
    int bMinChange = 0;
    int bMaxChange = 0;
    bool bNone = false;

    int eMin = 0;
    int eMax = 0;
    int eMinChange = 0;
    int eMaxChange = 0;
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
                bMin = std::max(bMin, bTempMin);
                bMax = std::min(bMax, bTempMax);
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

            // subtracting so flipped
            bMinChange -= bTempMax;
            bMaxChange -= bTempMin;

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

    std::cout << bMin << std::endl;
    std::cout << bMax << std::endl;
    
    fin.seekg(0, std::ios::beg);
    fin >> n;
    for (int i = 0; i < n; i++)
    {   
        String type;
        fin >> type;
        if (type == "none")
        {
            if (eNone == false)
            {
                eNone = true;
                fin >> eMin >> eMax;
                eMinChange = 0;
                eMaxChange = 0;
            }
            else
            {
                int eTempMin;
                int eTempMax;
                fin >> eTempMin >> eTempMax;
                eMin = std::max(eMin, eTempMin);
                eMax = std::min(eMax, eTempMax);
            }
        }
        else if (type == "on")
        {
            if (eNone == true)
            {
                eNone = false;
            }
            int eTempMin;
            int eTempMax;
            fin >> eTempMin >> eTempMax;
            
            eMinChange += eTempMin;
            eMaxChange += eTempMax;

        }
        else if (type == "off")
        {
            if (eNone == true)
            {
                eNone = false;
            }
            int eTempMin;
            int eTempMax;

            fin >> eTempMin >> eTempMax;

            // subtracting so flipped
            eMinChange -= eTempMax;
            eMaxChange -= eTempMin;
        }
    }
    eMin += eMinChange;
    eMax += eMaxChange;

    eMin = std::max(0, eMin);
    eMax = std::max(0, eMax);

    std::cout << eMin << std::endl;
    std::cout << eMax << std::endl;

    std::ofstream fout("traffic.out");

    fout << bMin << " " << bMax << std::endl;
    fout << eMin << " " << eMax << std::endl;
}
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
    int bMinChangeStored = 0;
    int bMaxChangeStored = 0;
    bool bFirstNone = false;
    bool bNone = false;
    bool bStoreMode = false;

    int eMin = 0;
    int eMax = 0;
    int eMinChange = 0;
    int eMaxChange = 0;
    bool eFirstNone = false;
    bool eNone = false;
    for (int i = 0; i < n; i++)
    {
        String type;
        fin >> type;

        if (type == "none")
        {
            if (bNone == false)
            {
                int bTempMin;
                int bTempMax;
                fin >> bTempMin >> bTempMax;
                if (bFirstNone)
                {
                    if ((bTempMax - bTempMin) < (bMax - bMin))
                    {
                        bNone = true;
                        bMin = bTempMin;
                        bMax = bTempMax;
                        bMinChange += bMinChangeStored;
                        bMaxChange += bMaxChangeStored;
                        bMinChangeStored = 0;
                        bMaxChangeStored = 0;
                        std::cout << "Override" << std::endl;
                    }
                    else
                    {
                        std::cout << "Ignore" << std::endl;
                    }
                }
                else
                {
                    std::cout << "First None" << std::endl;
                    bFirstNone = true;
                    bNone = true;
                    bMin = bTempMin;
                    bMax = bTempMax;
                }
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
                bNone = false;
                bStoreMode = true;
            }
            int bTempMin;
            int bTempMax;
            fin >> bTempMin >> bTempMax;

            // subtracting so flipped
            if (bStoreMode)
            {
                bMinChangeStored -= bTempMax;
                bMaxChangeStored -= bTempMin;
            }
            else
            {
                bMinChange -= bTempMax;
                bMaxChange -= bTempMin;
            }
        }
        else if (type == "off")
        {
            if (bNone == true)
            {
                bNone = false;
                bStoreMode = true;
            }

            int bTempMin;
            int bTempMax;
            fin >> bTempMin >> bTempMax;

            if (bStoreMode)
            {
                bMinChangeStored += bTempMin;
                bMaxChangeStored += bTempMax;
            }
            else
            {
                bMinChange += bTempMin;
                bMaxChange += bTempMax;
            }
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
                int eTempMin;
                int eTempMax;
                fin >> eTempMin >> eTempMax;
                if (eFirstNone)
                {
                    if ((eTempMax - eTempMin) < (eMax - eMin))
                    {
                        eMin = eTempMin;
                        eMax = eTempMax;
                        eMinChange = 0;
                        eMaxChange = 0;
                        eNone = true;
                    }
                }
                else
                {
                    eFirstNone = true;
                    eMin = eTempMin;
                    eMax = eTempMax;
                    eMinChange = 0;
                    eMaxChange = 0;
                    eNone = true;
                }
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
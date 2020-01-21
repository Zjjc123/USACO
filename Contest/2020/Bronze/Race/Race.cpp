/*
ID: zjjc123
TASK: Race
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::ifstream fin("race.in");
    std::ofstream fout("race.out");

    int distance;
    fin >> distance;

    int count;
    fin >> count;

    for (int i = 0; i < count; i++)
    {
        std::cout << i << "====================================" << std::endl;
        int max;
        fin >> max;

        int speed = 0;

        int timeTotal = 0;
        int timeBefore = 0;


        int traveled = 0;
        int traveledAfterMaxSpeed = 0;


        double tdAfterReachedSpeed = 0;
        bool reachedSpeed = false;

        while (traveled < distance)
        {
            std::cout << "Time " << timeTotal << "================" << std::endl;
            // If speed is stil less than max add speed;
            if (speed < max)
            {
                speed++;
                std::cout << "Less than max add 1 to speed to become: " << speed << std::endl;
                timeBefore++;
            }
            else
            {
                // If just reached speed, record down remaining distance
                if (reachedSpeed == false)
                {
                    tdAfterReachedSpeed = distance - traveled;
                    reachedSpeed = true;
                    std::cout << "First time, left distance: " << tdAfterReachedSpeed << std::endl;
                }

                // If adding speed is still less than half way
                if (traveledAfterMaxSpeed < tdAfterReachedSpeed/2)
                {
                    if (traveledAfterMaxSpeed + speed + 1 > tdAfterReachedSpeed/2)
                    {
                        std::cout << "Adding speed would go over half of remaining distance of " << tdAfterReachedSpeed << std::endl;
                        std::cout << "Time before: " << timeBefore << std::endl;
                        std::cout << "Time total: " << timeTotal << std::endl;
                        timeTotal = timeBefore + (timeTotal - timeBefore) * 2 + 1;
                        break;
                    }
                    else if (traveledAfterMaxSpeed + speed + 1 == tdAfterReachedSpeed/2)
                    {
                        timeTotal = timeBefore + (timeTotal - timeBefore) * 2;
                        std::cout << "Adding speed reaches perfect the half distance of " << tdAfterReachedSpeed << std::endl;
                        std::cout << "Time before: " << timeBefore << std::endl;
                        std::cout << "Time total: " << timeTotal << std::endl;
                        break;
                    }
                    else
                    {   
                        speed++;
                        std::cout << "Add Speed to " << speed << std::endl;
                    }
                                    // Record down distance traveled after reached max speed     
                    traveledAfterMaxSpeed += speed;           
                    std::cout << "Distance after reached max speed: " << traveledAfterMaxSpeed << std::endl;
                }
            }
            
            traveled += speed;
            timeTotal++;
            std::cout << "Traveled " << traveled << std::endl;

        }

        fout << timeTotal << std::endl;
    }
}
/*
ID: zjjc123
TASK: 
LANG: C++                 
*/

/*
Solution:

 */

#include <fstream>
#include <iostream>

struct Cow
{
    int arrival, eatTime, waitTime;
    bool isWaiting;
    bool isFinished;
};

bool operator==(const Cow& a, const Cow& b) {
    return (a.arrival == b.arrival && a.eatTime == b.eatTime && a.waitTime == b.waitTime);
}


int main()
{
    std::ifstream fin("TestData/1.in");
    int N;
    fin >> N;

    int max = 0;
    Cow cows[N];
    for (int i = 0; i < N; i++)
    {
        fin >> cows[i].arrival >> cows[i].eatTime;
        if (cows[i].arrival > max)
            max = cows[i].arrival;
        cows[i].waitTime = 0;
        cows[i].isWaiting = false;
        cows[i].isFinished = false;
        std::cout << cows[i].arrival << std::endl;
    }

    bool isUsed = false;
    Cow *currentCow;
    int currentDuration = 0;

    // From beginning of time to end
    for (int i = 0; i < max; i++)
    {
        std::cout << "Time: " << i << std::endl;
        std::cout << "Pasture Usage: " << (isUsed ? "True" : "False") << std::endl;
        currentDuration++;
        // If the pasture is not used
        if (!isUsed)
        {
            // For every cow if it is arriving at time j = i, field is not used, then set it to using and keep track of duration
            // if it is used then keep track of wait time
            for (int j = 0; j < N; j++)
            {
                if (cows[j].arrival <= i)
                {
                    if (isUsed == false)
                    {
                        std::cout << "Cow " << j << " Started" << std::endl;
                        currentCow = &cows[j];
                        isUsed = true;
                        cows[j].isWaiting = false;
                        currentDuration = 0;
                    }
                    else
                    {
                        std::cout << "Cow " << j << " is waiting for " << cows[j].waitTime << " minutes" << std::endl;
                        cows[j].isWaiting = true;
                        cows[j].waitTime++;
                    }
                }
                if (cows[j].isWaiting)
                    cows[j].waitTime++;
            }
        }
        // If the pasture is being used
        else
        {
            // And if the current cow has finished
            if (currentDuration == currentCow->eatTime)
            {
                std::cout << "Cow Finished" << std::endl;
                currentCow->isFinished = true;
                isUsed = false;
                for (int j = 0; j < N; j++)
                {
                    if (cows[j].arrival <= i)
                    {
                        if (isUsed == false)
                        {
                            std::cout << "Cow " << j << " Started" << std::endl;
                            currentCow = &cows[j];
                            cows[j].isWaiting = false;
                            isUsed = true;
                            currentDuration = 0;
                        }
                        else
                        {
                            std::cout << "Cow " << j << " is waiting for " << cows[j].waitTime << " minutes" << std::endl;
                            cows[j].isWaiting = true;
                            cows[j].waitTime++;
                        }
                    }
                    if (cows[j].isWaiting)
                        cows[j].waitTime++;
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if (cows[j].arrival <= i && !(cows[j] == *currentCow))
                    {
                        cows[j].isWaiting = true;
                    }
                    if (cows[j].isWaiting)
                    {
                        std::cout << "Cow " << j << " is waiting for " << cows[j].waitTime << " minutes" << std::endl;
                        cows[j].waitTime++;
                    }
                }
            }
        }
    }

    max = 0;

    for (int i = 0; i < N; i++)
    {
        if (cows[N].waitTime > max)
            max = cows[N].waitTime;
    }

    std::cout << max << std::endl;
}

// Common Code: 3221225477 (access violation)
// Common Code: 3221225725 (exceed stack size)

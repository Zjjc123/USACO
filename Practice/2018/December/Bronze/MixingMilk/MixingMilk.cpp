/*
ID: zjjc123
TASK: Mixing Milk
LANG: C++                 
*/

/*
Solution:
 */

#include <fstream>
#include <iostream>

/* Solution:
    Brute force?
*/

struct bucket
{
    int cap;
    int milk;
};

void Pour(int & current, bucket & cow1, bucket & cow2, bucket & cow3)
{
    if (current == 1)
    {
        // space left in "to" bucket
        int space = cow2.cap - cow2.milk;
        // if there is enough space for all milk
        if (cow1.milk <= space)
        {   // pour all milk from 1 to 2
            cow2.milk = cow2.milk + cow1.milk;
            cow1.milk = 0;
        }
        // if there isn't enough space
        else
        {
            // pour amount of milk that can fit from 1 to 2
            cow1.milk = cow1.milk - space;
            cow2.milk = cow2.cap;
        }
        // passed by reference so can change value
        current = 2;
    }
    else if (current == 2)
    {
        int space = cow3.cap - cow3.milk;
        if (cow2.milk <= space)
        {
            cow3.milk = cow3.milk + cow2.milk;
            cow2.milk = 0;
        }
        else
        {
            cow2.milk = cow2.milk - space;
            cow3.milk = cow3.cap;
        }
        // passed by reference
        current = 3;
    }
    else 
    {
        int space = cow1.cap - cow1.milk;
        if (cow3.milk <= space)
        {
            cow1.milk = cow1.milk + cow3.milk;
            cow3.milk = 0;
        }
        else
        {
            cow3.milk = cow3.milk - space;
            cow1.milk = cow1.cap;
        }
        // passed by reference
        current = 1;
    }
}

int main()
{
    std::ifstream fin("mixmilk.in");
    bucket cow1, cow2, cow3;

    int currentPCow = 1;

    fin >> cow1.cap >> cow1.milk;
    fin >> cow2.cap >> cow2.milk;
    fin >> cow3.cap >> cow3.milk;

    for (int i = 0; i < 100; i++)
    {
        Pour(currentPCow, cow1, cow2, cow3);
        std::cout << "current Cow: " << currentPCow << std::endl; 
        std::cout << cow1.milk << std::endl << cow2.milk << std::endl << cow3.milk << std::endl;
    }

    std::ofstream fout("mixmilk.out");
    fout << cow1.milk << std::endl << cow2.milk << std::endl << cow3.milk;
}
/*
ID: zjjc123
TASK: Sleepy Cow Sorting
LANG: C++                 
*/

/*
Solution:

If I can prove the lowest amount of cows that NEED to be moved is able to solve the
problem then that is the solution to the problem

The lowest amount of cows that HAVE to be moved is the amount of cows up to the last decrease
Since if the order is wrong, a cow has to be moved. But if the order is wrong, all the cows infront has to be 
moved as well to reach the last cow in the incorrect order.

By moving the lowest amount of cows would be able to solve the problem. It's basically insertion sort into the
last incorrect order.


1 2 3 5 4
1 2 3 (5) | 4
2 3 (5) | 1 4
3 (5) | 1 2 4
(5) | 1 2 3 4
1 2 3 4 5



 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin("sleepy.in");
    int length;
    // Get length
    fin >> length;

    int lastCow;
    int firstCorrectIndex;
    
    fin >> lastCow;
    
    for (int i = 1; i < length; i++)
    {
        int currentCow;
        fin >> currentCow;

        if (currentCow < lastCow)
        {
            firstCorrectIndex = i;
        }

        lastCow = currentCow;
    }

    std::ofstream fout("sleepy.out");
    fout << (firstCorrectIndex) << std::endl;

    return 0;
}
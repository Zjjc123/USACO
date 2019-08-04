/*
ID: zjjc123
TASK: Sleepy Cow Herding
LANG: C++                 
*/

/*
Solution:
I feel like this problem is a problem based on conditions
Lets start with 2 gaps  x---a----x-----b---- 
a & b
for the lowest amount of moves, its always 0, 1, or 2
    if the cows are already in order then the move is 0 (gap a and b are both 1)
    else if one of the gap is 2 --> then just move the other cow in
    else the outer could be moved to be 1 apart from the middle and another move to
        the other cow in (2 moves)
for the highest amount of moves, just count the largest gap (a or b)
this is true because the least amount of space shortened is 1 by each move and
    using the largest gap maximizes the moves
 */


#include <fstream>

int main()
{
    std::ifstream fin("herding.in");
    std::ofstream fout("herding.out");
    int gapA;
    int gapB;

    int cow1;
    int cow2;
    int cow3;

    fin >> cow1;
    fin >> cow2;
    fin >> cow3;

    gapA = cow2 - cow1;
    gapB = cow3 - cow2;

    if (gapA == 1 && gapB == 1)
        fout << 0 << std::endl;
    else if (gapA == 2 || gapB == 2)
        fout << 1 << std::endl;
    else
        fout << 2 << std::endl;

    if (gapA > gapB)
        fout << (gapA - 1) << std::endl;
    else
        fout << (gapB - 1) << std::endl;

}
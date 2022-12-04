#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("day4.in");

char delims[] = "-,";

bool fullyContain(int a, int b, int c, int d)
{
    if (a < c && b < d) //multimea vida
        return false;

    if (a > c && b > d)
        return false;
    
    return true;
}

int myStoi(char *c)
{
    int digit;
    int len = strlen(c);
    int nr = 0;
    for (int i = 0; i < len; i++)
    {
        digit = c[i] - '0';
        nr = nr * 10 + digit;
    }

    return nr;
}

bool overlap(int a, int b, int c, int d)
{
    if (a <= d && b >= c)
    {
        return true;
    }

    return false;
}

int main()
{
    char input[12];
    int k;
    char *line;
    int nums[4];
    int ans = 0;
    while(fin.getline(input, 12))
    {
        line = strtok(input, delims);
        k = 0;
        while(line)
        {
            nums[k++] = myStoi(line);

            line = strtok(NULL, delims);
        }

        // //Part 1
        // if (fullyContain(nums[0], nums[1], nums[2], nums[3]))
        // {
        //     ans++;
        // }

        //Part 2
        if(overlap(nums[0], nums[1], nums[2], nums[3]))
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
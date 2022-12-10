#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("day10.in");

#define MAX_SIZE 9

int cycleCounter(char *input)
{
    if (input == "noop") return 1;
    if (input[0] == 'a') return 2; //addx

    return 0;
}

int myStoi(char *input)
{
    int i;
    if (input[0] == '-') i = 1;
    else i = 0;

    int ans = 0;
    int digit;
    int len = strlen(input);
    for (i; i < len; i++)
    {
        digit = input[i] - '0';
        ans = ans * 10 + digit;
    }

    if (input[0] == '-') return ans * -1;

    return ans;
}

int getAddxValue(char *input)
{
    return myStoi(input + 5);
}

int cycle = 0;
int X = 1;
int V = 0;
int signalStrength;

void part1(char *input, int &ans)
{
    cycle++;
    if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
    {
        signalStrength = cycle * X;
        ans += signalStrength;
    }
    
    if (cycleCounter(input) == 2)
    {   
        cycle++;

        V = getAddxValue(input);
        X += V;
        
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
        {
            signalStrength = cycle * (X - V);
            ans += signalStrength;
        }
    }
}

int main()
{
    char input[MAX_SIZE];
    int ans = 0;
    while (fin.getline(input, MAX_SIZE))
    {
        part1(input, ans);
    }
    cout << ans;

    return 0;
}

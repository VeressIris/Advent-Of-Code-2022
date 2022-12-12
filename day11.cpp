#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

ifstream fin("day11.in");

#define MAX_SIZE 50 //actually 49 but i rounded it up
#define OLD 6952 //stoi value of the word "old"

struct monkey
{
    vector<int> startingItems; 
    char opSign;
    int opNumber;
    int testNumber;
    int trueDest;
    int falseDest;
    int inspectCount = 0;
    int index;
} monkeys[8]; //8 monkeys in puzzle input

int myStoi(char *input)
{
    int len = strlen(input);
    if (input[strlen(input) - 1] == '\n') //ignore new line char for the last numbers
    {
        len--;
    }

    int ans = 0;
    int digit;
    for (int i = 1; i < len; i++)
    {
        digit = input[i] - '0';
        ans = ans * 10 + digit;
    }

    return ans;
}

void assignMonkeyVals(char *input, int index)
{
    if (input[2] == 'S')
    {
        char *p = strtok(input + 17, ","); // +17 to skip the words
        while(p)
        {
            for (int i = 0; i < strlen(p); i++)
            {
                if (isdigit(p[i]))
                {
                    monkeys[index].startingItems.push_back(myStoi(p));
                    break;
                }
            }
            
            p = strtok(NULL, ",");
        }
    }
    else if (input[2] == 'O')
    {
        monkeys[index].opSign = input[23];
        monkeys[index].opNumber = myStoi(input + 24);
    }
    else if (input[2] == 'T')
    {
        monkeys[index].testNumber = myStoi(input + 21);
    }
    else if (input[7] == 't')
    {
        monkeys[index].trueDest = myStoi(input + 28);
    }
    else if (input[7] == 'f')
    {
        monkeys[index].falseDest = myStoi(input + 29);
    }
}

int processInput(char *input, FILE *file)
{
    int monkeyNr = 0;

    while(true)
    {
        if (fgets(input, MAX_SIZE, file))
        {
            if (*input != '\n')
            {
                assignMonkeyVals(input, monkeyNr);
            }
            else //move onto next monkey
            {
                monkeys[monkeyNr].index = monkeyNr;
                monkeyNr++;
            }
        }
        else
        {
            monkeys[monkeyNr].index = monkeyNr;
            monkeyNr++; //get the last monkey
            break;
        }
    }

    return monkeyNr;
}

float operation(float old, int index)
{
    if (monkeys[index].opNumber == OLD)
    {
        monkeys[index].opNumber = old;
    }
    
    if (monkeys[index].opSign == '*')
    {
        return old * monkeys[index].opNumber;
    }
    else if (monkeys[index].opSign == '+')
    {
        return old + monkeys[index].opNumber;
    }
    
    return 0;
}

void sortByInspectCount(int monkeyNr)
{
    for (int i = 0; i < monkeyNr - 1; i++)
    {
        for (int j = i + 1; j < monkeyNr; j++)
        {
            if (monkeys[i].inspectCount < monkeys[j].inspectCount)
            {
                swap(monkeys[i].inspectCount, monkeys[j].inspectCount);
                swap(monkeys[i].index, monkeys[j].index);
            }
        }
    }
}

int main()
{
    FILE *file = fopen("day11.in", "r");
    char input[MAX_SIZE];

    int k = processInput(input, file); //nr of monkeys
    float old;
    float newW;
    int itemCount;
    int dest;
    for (int r = 0; r < 20; r++)
    {
        for (int i = 0; i < k; i++)
        {
            itemCount = monkeys[i].startingItems.size();
            for (int j = 0; j < itemCount; j++)
            {
                old = monkeys[i].startingItems[j];
                newW = operation(old, i);

                monkeys[i].inspectCount++;
                
                newW = floor(newW / 3);
                if ((int)newW % monkeys[i].testNumber == 0)
                {
                    dest = monkeys[i].trueDest;
                }
                else
                {
                    dest = monkeys[i].falseDest;
                }
                monkeys[dest].startingItems.push_back(newW);
                monkeys[i].startingItems.erase(monkeys[i].startingItems.begin());
            }
        }
    }

    // sortByInspectCount(k);
    // int monkeyBusiness = 1;
    // for (int i = 0; i < k; i++)
    // {
    //     cout << "monkey " << monkeys[i].index << " inspected items " << monkeys[i].inspectCount << " times\n";
    //     monkeyBusiness *= monkeys[i].inspectCount;
    // }
    // cout << monkeyBusiness;
    
    return 0;
}
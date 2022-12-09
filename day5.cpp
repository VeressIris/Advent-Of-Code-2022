#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

ifstream fin ("day5.in");

#define SIZE 36 //counted maximum chars from puzzle input, it's 35 (+1 for '\0')

int myStoi(char *s)
{
    int len = strlen(s);
    int l = len;
    if (s[len - 1] == '\n')
    {
        l = len - 1;
    }

    int digit;
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        digit = s[i] - '0';
        ans = ans * 10 + digit;
    }

    return ans;
}

struct command{
    int nrOfMoves;
    int startPos;
    int destination;
};

//puts all numbers from the commands into an array
void getCommandNumbers(char input[SIZE], int commands[SIZE][SIZE], int &i, int &j)
{
    char *p;
    p = strtok(input, " ");
    j = 0;
    while(p != NULL)
    {
        if (isdigit(p[0]))
        {
            commands[i][j] = myStoi(p);
            j++;
        }
        p = strtok(NULL, " ");
    }

    i++;
}

//splits input into stacks and commands
void splitInput(char crateStack[SIZE][SIZE], int commands[SIZE][SIZE])
{
    char input[SIZE];
    FILE *file = fopen("day5.in", "r");

    int i = 0;
    while(true)
    {
        if (fgets(input, SIZE, file))
        {
            if (*input == '\n')
            {
                break;
            }
            else
            {
                strcpy(crateStack[i++], input);
            }
        }
    }

    i = 0;
    int j = 0;
    while(true)
    {
        if (fgets(input, SIZE, file))
        {
            if (*input != '\n')
            {
                getCommandNumbers(input, commands, i, j);
            }
        }
        else
        {
            break;
        }
    }
}

void createStacks(char crateStack[SIZE][SIZE], stack<char> stacks[9], int &n)
{
    int stackLen = strlen(*crateStack);
    int index = 0;
    for (int i = 0; i < stackLen - 9; i++) //i kept subtracting until i only got the crates, without the numbers and random chars at the end (thats why it's -9)
    {    
        for (int j = strlen(crateStack[i]) - 1; j >= 0; j--)
        {
            if (j % 4 == 0)
            {
                stacks[index].push((char)crateStack[i][j + 1]);
            }
        }
        
        index++;
    }

    n = index; //number of rows in stack
}

void part1(stack<char> stacks[9], int commands[SIZE][SIZE], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        while(!stacks[i].empty())
        {
            cout << stacks[i].top();
            stacks[i].pop();
        }
        cout << endl;
    }
}

int main()
{
    char crateStack[SIZE][SIZE];
    int commands[SIZE][SIZE];
    splitInput(crateStack, commands);

    stack<char> stacks[9];
    int n;
    createStacks(crateStack, stacks, n);

    part1(stacks, commands, n);

    // //print the stack
    // for (int i = 0; i < n; i++)
    // {
    //     while(!stacks[i].empty())
    //     {
    //         cout << stacks[i].top();
    //         stacks[i].pop();
    //     }
    //     cout << endl;
    // }

    return 0;
}
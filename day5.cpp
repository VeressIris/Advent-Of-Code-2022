#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

ifstream fin ("day5.in");

#define SIZE 36 //counted maximum chars from puzzle input, it's 35 (+1 for '\0')

//splits input into stacks and commands
void splitInput(char crateStack[SIZE][SIZE], char commands[SIZE][SIZE])
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
    while(true)
    {
        if (fgets(input, SIZE, file))
        {
            if (*input != '\n')
            {
                strcpy(commands[i++], input);
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

    n = index;
}



int main()
{
    char crateStack[SIZE][SIZE];
    char commands[SIZE][SIZE];
    splitInput(crateStack, commands);

    int n;
   stack<char> stacks[9];
   createStacks(crateStack, stacks, n);


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

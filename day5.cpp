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

void createStacks(char crateStack[SIZE][SIZE], stack<char> stacks[9])
{
    int i = 0;
    int j = 0;
    while(crateStack[i] != '\0')
    {
        cout << crateStack[i];
//        if (isupper(crateStack[i]))
//        {
//            stacks[j++].push(crateStack[i]);
//        }

        i++;
    }
}

int main()
{
    //!i think i have to turn these into char vectors
    char crateStack[SIZE][SIZE];
    char commands[SIZE][SIZE];
    splitInput(crateStack, commands);
    strcpy(crateStack[3], '\0');
    strcpy(commands[4], '\0');

    int i =0;
    while(crateStack[i] != '\0')
    {
        cout << crateStack[i];
        i++;
    }

//    stack<char> stacks[9];
//    createStacks(crateStack, stacks);


//    for (int i = 0; i < 3; i++)
//    {
//        while(!stacks[i].empty())
//        {
//            cout << stacks[i].top() << ' ';
//            stacks[i].pop();
//        }
//        cout << endl;
//    }

    return 0;
}

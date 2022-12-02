#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("advent2.in");

int outcome(char enemyInput, char myInput)
{
    //I win
    if ((enemyInput == 'A' && myInput == 'Y') ||
        (enemyInput == 'B' && myInput == 'Z') || 
        (enemyInput == 'C' && myInput == 'X'))
        return 1;
    
    //draw
    if(enemyInput - 'A' + 1 == myInput - 'X' + 1) //numbers each of the inputs to 1, 2 or 3 accordingly so I don't have to add cases by hand
        return 0;

    //I lose
    return -1;
}

int main()
{
    string input;
    char enemyInput;
    char myInput;
    int score = 0;
    while (getline(fin, input))
    {
        enemyInput = input[0];
        myInput = input[2];

        switch (myInput)
        {
        case 'X': //Rock (1p)
            score += 1;
            break;
        case 'Y': //Paper (2p)
            score += 2;
            break;
        case 'Z': //Scissors (3p)
            score += 3;
            break;
        default:
            break;
        }

        if(outcome(enemyInput, myInput) == 1)
        {
            score += 6;
        }
        else if (outcome(enemyInput, myInput) == 0)
        {
            score += 3;
        }
    }

    cout << score;

    return 0;
}
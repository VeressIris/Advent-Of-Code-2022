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

void part1(char enemyInput, char myInput, int &score)
{
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

void losingInputs(char enemyInput, int &score)
{
    switch (enemyInput)
    {
    case 'A': //I need to play scissors
        score += 3;
        break;
    case 'B': //I need to play rock
        score += 1;
        break;
    case 'C': //I need to paper
        score += 2;
        break;
    default:
        break;
    }
}

void drawInput(char enemyInput, int &score)
{
    switch (enemyInput)
    {
    case 'A':
        score += 1;
        break;
    case 'B':
        score += 2;
        break;
    case 'C':
        score += 3;
        break;
    default:
        break;
    }
}

void winningInputs(char enemyInput, int &score)
{
    switch (enemyInput)
    {
    case 'A': //I need to play paper
        score += 2;
        break;
    case 'B': //I need to play scissors
        score += 3;
        break;
    case 'C': //I need to play rock
        score += 1;
        break;
    default:
        break;
    }
}

void part2(char enemyInput, char myInput, int &score)
{
    switch (myInput)
    {
    case 'X': //Loss
        losingInputs(enemyInput, score);
        break;
    case 'Y': //Draw
        drawInput(enemyInput, score);
        score += 3;
        break;
    case 'Z': //Win
        winningInputs(enemyInput, score);
        score += 6;
        break;
    default:
        break;
    }
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

        // part1(enemyInput, myInput, score);
        part2(enemyInput, myInput, score);
    }

    cout << score;

    return 0;
}
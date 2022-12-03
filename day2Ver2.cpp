//?Not sure how much more optimal this solution is but it sure is shorter than the first one i came up with
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream fin("advent2.in");

enum Shapes {Rock = 1, Paper = 2, Scissors = 3}; //stores amount of points for each shape

map <char, Shapes> shapeValues = {{'A', Rock}, {'B', Paper}, {'C', Scissors},
                                  {'X', Rock}, {'Y', Paper}, {'Z', Scissors}};

map <char, char> winningMap = {{'X', 'C'}, {'Y', 'A'}, {'Z', 'B'}, //when i win
                                {'A', 'Z'}, {'B', 'X'}, {'C', 'Y'}}; //when my oponent wins

void part1(char enemyInput, char myInput, int &score)
{
    score += shapeValues[myInput];

    if (shapeValues[myInput] == shapeValues[enemyInput]) //DRAW
    {
        score += 3;
    }
    else if (winningMap[myInput] == enemyInput) //WIN
    {
        score += 6;
    }
}

void part2(char enemyInput, char myInput, int &score)
{
    if (myInput == 'Y') //DRAW
    {
        myInput = enemyInput;
        score += 3;
    }
    else if (myInput == 'Z') //WIN
    {
        score += 6;

        for (auto map : winningMap)
        {
            //find matching key for enemyInput value
            if (map.second == enemyInput)
            {
                myInput = map.first;
                break;
            }
        }
    }
    else //LOSE
    {
        myInput = winningMap[enemyInput];
    }
    
    score += shapeValues[myInput];
}

int main()
{
    string input;
    char enemyInput;
    char myInput;
    int score = 0;
    while(getline(fin, input))
    {
        enemyInput = input[0];
        myInput = input[2];

        //part1(enemyInput, myInput, score);
        part2(enemyInput, myInput, score);
    }

    cout << score;

    return 0;
}
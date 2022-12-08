#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin ("day8.in");

#define SIZE 99

void generateTrees(int trees[SIZE][SIZE], int &n, int &m)
{
    string input;
    int len;
    while(fin >> input)
    {
        len = input.length();
        for (int j = 0; j < len; j++)
        {
            trees[n][j] = input[j] - '0';
        }

        n++;
    }

    m = len;
}

int part1(int row, int col, int trees[SIZE][SIZE])
{
    int ans = 0;
    int treeHeight;
    bool visible;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            treeHeight = trees[i][j];

            //check left
            for (int jj = j - 1; jj >= 0; jj--)
            {
                if (treeHeight <= trees[i][jj])
                {
                    visible = false;
                    break;
                }
            }
            if (visible)
            {
                ans++;
                continue;
            }

            //check right
            for (int jj = j + 1; jj < col; jj++)
            {
                if (treeHeight <= trees[i][jj])
                {
                    visible = false;
                    break;
                }
            }
            if (visible)
            {
                ans++;
                continue;
            }

            //check above
            for (int ii = i - 1; ii >= 0; ii--)
            {
                if (treeHeight <= trees[ii][j])
                {
                    visible = false;
                    break;
                }
            }
            if (visible)
            {
                ans++;
                continue;
            }

            //check below
            for (int ii = i + 1; ii < row; ii++)
            {
                if (treeHeight <= trees[ii][j])
                {
                    visible = false;
                    break;
                }
            }
            if (visible)
            {
                ans++;
            }
        }
    }

    return ans;
}

int part2(int row, int col, int trees[SIZE][SIZE])
{
    int ans = 0;
    int treeHeight;
    int score = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            treeHeight = trees[i][j];
            score = 1;
            int directionScore[4] = {0};

            //check left
            for (int jj = j - 1; jj >= 0; jj--)
            {
                directionScore[0]++;
                if (treeHeight <= trees[i][jj])
                {
                    break;
                }
            }
            
            //check right
            for (int jj = j + 1; jj < col; jj++)
            {
                directionScore[1]++;
                if (treeHeight <= trees[i][jj])
                {
                    break;
                }
            }
            
            //check above
            for (int ii = i - 1; ii >= 0; ii--)
            {
                directionScore[2]++;
                if (treeHeight <= trees[ii][j])
                {
                    break;
                }
            }
            
            //check below
            for (int ii = i + 1; ii < row; ii++)
            {
                directionScore[3]++;
                if (treeHeight <= trees[ii][j])
                {
                    break;
                }
            }
            
            for (auto x : directionScore)
            {
                score *= x;   
            }

            if (score > ans)
            {
                ans = score;
            }
        }
    }

    return ans;
}

int main()
{
    int trees[SIZE][SIZE];
    int row = 0;
    int col = 0;
    generateTrees(trees, row, col);
    
    //cout << part1(row, col, trees);
    cout << part2(row, col, trees);
    
    return 0;
}

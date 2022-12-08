#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin ("day6.in");

void generateTreeMatrix(int trees[100][100], int &row)
{
    string input;
    int len;
    while(fin >> input)
    {
        len = input.length();
        for (int j = 0; j < len; j++)
        {
            trees[row][j] = input[j] - '0';
        }

        row++;
    }
}

bool visible(int ii, int jj, int row, int trees[100][100])
{
    if (ii == 0 || jj == 0 || ii == row - 1 || jj == row - 1)
    {
        return true;
    }

    //check all other trees around current tree
    int treeHeight = trees[ii][jj];
    for (int i = ii; i >= 0; i--)
    {
        for (int j = jj; j >= 0; j--)
        {
            if (treeHeight > trees[ii][jj - 1] || treeHeight > trees[ii][jj + 1] ||
                treeHeight > trees[ii - 1][jj] || treeHeight > trees[ii + 1][jj])
            {
                ans++;
            }
        }
    }

    return false;
}

int main()
{
    int trees[100][100];
    int row = 0;
    generateTreeMatrix(trees, row);

    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (visible(i, j, row, trees))
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}

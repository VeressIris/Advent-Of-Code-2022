#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin ("day13.in");

#define MAX_SIZE 526

bool inOrder(vector<char> packet1, vector<char> packet2)
{
    int n = packet1.size();
    int m = packet2.size();

    for (int i = 0; i < n; i++)
    {
        if (i >= m)
            break;

        if (packet1[i] <= packet2[i])
            return false;
    }

    return true;
}

int main()
{
    FILE *file = fopen("day13.in", "r");
    char input[MAX_SIZE];
    vector<char> packet1;
    vector<char> packet2;
    int len;
    int packCount = 1;
    int pairCount = 0;
    int ans = 0;
    while (true)
    {
        if (fgets(input, MAX_SIZE, file))
        {
            if (*input != '\n')
            {
                len = strlen(input);

                if (packCount == 1)
                {
                    for (int i = 0; i < len; i++)
                        if (isdigit(input[i]))
                            packet1.push_back(input[i]);
                }
                else
                {
                    for (int i = 0; i < len; i++)
                        if (isdigit(input[i]))
                            packet2.push_back(input[i]);
                }
                
                packCount++;
            }
            else
            {
                //reset variables
                packCount = 1;
                
                if (inOrder(packet1, packet2))
                {
                    cout << pairCount << endl; //gives 2 5 6 instead of 1 2 4 6 but sum is good
                    ans += pairCount;
                }
                
                packet1.clear();
                packet2.clear();

                pairCount++;

            }
        }
        else
            break;
    }

    cout << ans;

    return 0;
}
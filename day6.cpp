#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin ("day6.in");

bool repeatingChars(string s)
{
    int i = 0;
    int j;

    while(s[i] != '\0')
    {
        j = i + 1;
        while(s[j] != '\0')
        {
            if (s[i] == s[j])
            {
                return true;
            }
        
            j++;
        }

        i++;
    }

    return false;
}

int part1(string input)
{
    int len = input.length();
    string substring;
    int ans;
    for (int i = 0; i < len; i++)
    {
        substring = input.substr(i, 4);

        if (!repeatingChars(substring))
        {
            ans = i + 4;
            break;
        }
    }

    return ans;
}

int part2(string input)
{
    int len = input.length();
    string substring;
    int ans;
    for (int i = 0; i < len; i++)
    {
        substring = input.substr(i, 14);

        if (!repeatingChars(substring))
        {
            ans = i + 14;
            break;
        }
    }

    return ans;
}

int main()
{
    string input;
    fin >> input;
    
    int ans;
    // ans = part1(input);
    ans = part2(input);

    cout << ans;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("day3.in");

int part1(string rucksack, int &sum)
{
    int half = rucksack.length() / 2;;
    string item1 = rucksack.substr(0, half);;
    string item2 = rucksack.substr(half, half);;
    int priority;

    for (int i = 0; i < item1.length(); i++)
    {
        if (item2.find(item1[i]) != string::npos)
        {
            if (islower(item1[i]))
            {
                priority = item1[i] - 'a' + 1;
            }
            else
            {
                priority = item1[i] - 38;
            }

            break;
        }
    }

    sum += priority;
}

int main()
{
    string rucksack;
    int sum = 0;
    int priority;
    int k = 1;
    char badge;
    string s1;
    string s2;
    while(fin >> rucksack)
    {
        //part1(rucksack, sum);

        if (k == 1) 
        {
            s1 = rucksack;
            k++;
        }
        else if (k == 2)
        {
            s2 = rucksack;
            k++;
        }  
            
        else
        {
            for (int i = 0; i < s1.length(); i++)
            {
                if (s2.find(s1[i]) != string::npos && rucksack.find(s1[i]) != string::npos)
                {
                    badge = s1[i];
                    break;
                }
            }

            if (islower(badge))
            {
                priority = badge - 'a' + 1;
            }
            else
            {
                priority = badge - 38;
            }

            sum += priority;
            
            k = 1;
        }
    }

    cout << sum;

    return 0;
}
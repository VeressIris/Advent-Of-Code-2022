#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//converts string to a number
int stringToInt(char *s)
{
    int ans = 0;
    int digit;
    for (int i = 0; i < strlen(s) - 1; i++)
    {
        digit = s[i] - '0';
        ans = ans * 10 + digit;
    }

    return ans;
}

int main()
{
    FILE *file = fopen("advent1.in", "r");
    char input[6]; //numbers have a max of 6 digits

    int ans = 0;
    int totalCals = 0;
    int number;
    while(true)
    {
        if(fgets(input, 6, file))
        {
            if (*input == '\n') //when a new line is detected
            {
                totalCals = 0; //move onto the next elf
            }
            else
            {
                //add up total calories per elf
                number = stringToInt(input);
                totalCals += number;
            }

            //find maximum number of calories
            if (totalCals > ans)
            {
                ans = totalCals;
            }
        }
        else //at the end of the file
        {
            break;
        }
    }

    cout << ans;

    fclose(file);

    return 0;
}
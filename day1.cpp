#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
                number = stoi(input);
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
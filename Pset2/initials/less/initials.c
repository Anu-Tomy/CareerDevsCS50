#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    string s = get_string();
    //print the first letter as an uppercase letter
    if(islower(s[0]))
        {
        printf("%c", toupper(s[0]));
        }
        else {
            printf("%c",s[0]);
        }
    // iterate over characters in strings
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(s[i]== 32) //ASCII code for space
        {
        printf("%c", toupper(s[i+1]));
        }
    }
printf("\n");
}
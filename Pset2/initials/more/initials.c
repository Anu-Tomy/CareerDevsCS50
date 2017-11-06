#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    //iterate over characters in strings
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //check for the first letter
        if (i == 0 && isalpha(s[0]))
        {
            printf("%c", toupper(s[0]));
        }
        else if ((s[i] == 32) && isalpha(s[i + 1])) //check for other spaces in the string
        {
            printf("%c", toupper(s[i + 1]));
        }
    }
    printf("\n");
    return 0;
}
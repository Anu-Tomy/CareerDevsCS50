#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,string argv[])
{
   if(argc!=2)
    {
        printf("Missing Command-Line Argument\n");
        return 1;
    }
    //check 2nd argument
    //printf("key =%s\n",argv[1]);
    //convert string(key) to int
    //atoi stands for ASCII to integer
    int key = atoi(argv[1]);

    printf("plaintext: ");
    string s = get_string();
    printf("ciphertext: ");
    //iterate over each character in the plain text string
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isupper(s[i]))
        {
            printf("%c", (((s[i] + key) - 65) % 26) + 65);
        }
        else if (islower(s[i]))
        {
            printf("%c", (((s[i] + key) - 97) % 26) + 97);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
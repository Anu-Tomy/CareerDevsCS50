#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check for 2 command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else
    {
        //check for alphabetical characters
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }
    }
    string key = argv[1];
    int keylen = strlen(key);
    //prompt user to enter plain text to encode
    printf("plaintext: ");
    string s = get_string();
    //output
    printf("ciphertext: ");
   //iterate over each character in the plain text string
   // j is the count use for iterate over each keycharacter
   for (int i = 0, j = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
          //get each keycharacter for each plaintext letter
            int keychar = toupper(key[j]) - 'A';
            if (isupper(s[i]))
            {
                printf("%c", (((s[i] + keychar) - 'A') % 26) + 'A');
            }
            else if (islower(s[i]))
            {
                printf("%c", (((s[i] + keychar) - 'a') % 26) + 'a');
            }
            //increment each keycharacter
            j++;
            //check for count goes back to 0 and wrap around if j reached the keylength
            j = j % keylen;
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}

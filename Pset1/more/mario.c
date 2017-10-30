#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = -1;
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while (n < 0 || n > 23);

    for (int row = 0; row < n; row++)
    {
        //Print spaces for left pyramid
        for (int s = 1; s < (n - row); s++)
        {
            printf(" ");
        }
        //Print hashes for left pyramid
        for (int lhash = 0; lhash <= row; lhash++)
        {
            printf("#");
        }
        //Print 2 gaps
        printf("  ");
        //Print hashes for right pyramid
        for (int rhash = 0; rhash <= row; rhash++)
        {
            printf("#");
        }

        printf("\n");

    }
    return 0;
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Input
    int n = -1;
    while (n < 0 || n > 23)
    {
        printf("Height: ");
        n = get_int();
    }

    //Output
    for (int row = 0; row < n; row++)
    {
        //print spaces
        for (int s = 0; s < (n - row) - 1; s++)
        {
            printf(" ");
        }
        //print # symbols.
        for (int h = 0; h < row + 2; h++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
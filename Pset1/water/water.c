#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Input
    printf("Minutes: ");
    int minutes;
    do
    {
        minutes = get_int();
    }
    while (minutes < 0);
    //Output
    printf("Bottles: %i\n", (minutes * 12));
}
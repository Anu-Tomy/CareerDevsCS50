#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Input
    printf("Minutes: ");
    int minutes = get_int();
    //Output
    printf("Bottles: %i\n", (minutes * 12));
}
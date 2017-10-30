#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void){
    float change;
    do
    {
        printf("O hai! How much change is owed?\n");
        change = get_float();
    }
    while(change < 0);

    int cents = round((change * 100));
    int coins = 0;

     for(int i = 0; cents > 0; i++)
     {
         if(cents >= 25)
         {
            cents = cents - 25;
            coins++;
         }
         else if(cents <= 25 && cents >= 10)
         {
            cents = cents - 10;
            coins++;
         }
         else if(cents <= 10 && cents >= 5)
         {
            cents = cents - 5;
            coins++;
         }

         else

         {
             cents = cents - 1;
             coins++;
         }
     }

    printf("%i\n", coins);

}
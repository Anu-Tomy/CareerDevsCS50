/*
 C program to sort N numbers in ascending order using Bubble sort
 and print both the given and the sorted array
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[100], num, c, i, j, swap;
    printf("Enter maximum size of Array : \n");
    num = get_int();
    printf("Enter elements of Array one by one: \n");
    for(c = 0; c < num; c++)
    {
     array[c] = get_int();
    }

    printf("Input Array is : \n");
    for(c = 0; c < num; c++)
    {
     printf("%d\n", array[c]);
    }

   /*Bubble sorting*/
   for(i = 0; i < num; i++)
   {
       for(j = 0; j<(num-i)-1; j++)
       {
           //Compare the adjacent positions
           if(array[j] < array[j+1]) //for decreasing order
           {
               swap = array[j];
               array[j] = array[j + 1];
               array[j + 1] = swap;
           }
       }
   }
   printf("Sorted in descending order:\n");
    for(i = 0; i < num; i++)
    {
     printf("%d\n", array[i]);
    }

    return 0;

 }
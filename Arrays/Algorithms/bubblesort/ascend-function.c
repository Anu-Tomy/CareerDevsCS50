/*
 C program to sort N numbers in ascending order using Bubble sort
 and print both the given and the sorted array
 Using function
 */
#include <cs50.h>
#include <stdio.h>

int bubblesort(int array[],int num);

int main(void)
{
  int array[100], i, num;
  printf("Enter maximum size of Array : \n");
  num = get_int();
  printf("Enter elements of Array one by one: \n");
  for(i = 0; i < num; i++)
  {
   array[i] = get_int();
  }

  printf("Input Array is : \n");
  for(i = 0; i < num; i++)
  {
   printf("%d\n", array[i]);
  }
  bubblesort(array,num);
  printf("Sorted in ascending order :\n");
  for(i = 0; i < num; i++)
  {
   printf("%d\n", array[i]);
  }
 return 0;
}

int bubblesort(int array[],int num)
{
 int swap;
 for (int i = 0; i < num-1; i++)
 {
  for (int j = 0; j < (num-i)-1; j++)
  {
   //Compare the adjacent positions
    if(array[j] > array[j+1])
     {
          swap = array[j];
          array[j] = array[j+1];
          array[j+1] = swap;
     }
   }
}
  return 0;
}
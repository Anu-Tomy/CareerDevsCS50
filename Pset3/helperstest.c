 /**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

int main(void)
{
    int array[100], n, s, flag = 0;
    printf("Enter maximum no.of array elements");
    n = get_int();
    printf("Enter array elements");
    for (i =0; i < n; i++)
    {
        array[i] = get_int();
    }
    printf("Enter element to search");
    s = get_int();
    for (i =0; i < n; i++)
    {
        if(array[i]== s)
        {
            flag = 1;
            printf("%d is found at position %d", s, array[i])
            break;

        }
        if(flag == 0)
        printf("%d is not found",s);
    }

}
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool search(int value, int values[], int n)
    {
        int flag = 0;
        //return false if n is negative
        if(n < 0)
        {
            return false;
        }
        for (i =0; i < n; i++)
        {
            if(values[i]== value)
            {
                return true;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return false;
        }
    }


// TODO: implement a sorting algorithm
/**
 * Sorts array of n values using bubble sort.
 */
void sort(int values[], int n)
{
  int i, j, swap;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (i - 1); j++)
        {
            if(values[j] > values[j+1])
            {
                swap = values[j];
                values[j] = values[j+1];
                values[j+1] = swap;
            }
        }
    }

    return 0;
}

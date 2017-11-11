 /**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

// TODO: implement a searching algorithm
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
//Using binary search
{
    int start = 0, end = n-1, mid;
    if (n < 0)
    {
        return false;
    }
    while (start <= end)
    {
        mid = (start + end) / 2;
        //if search value is at the middle return true
        if (value == values[mid])
        {
            return true;
        }
        //if search value is < mid, then look at only left side of array
        //so, change 'end' just before mid.
        else if (value < values[mid])
        {
            end = mid-1;
        }
        //else, search value > mid so change start position
            else
            {
                start = mid + 1;
            }
    }
    return false;
}
// TODO: implement a sorting algorithm
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //Bubble sort
    int swap;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i) - 1; j++)
        {
            //compare adjacent positions
            if (values[j] > values[j + 1])
            {
                swap = values[j];
                values[j] = values[j + 1];
                values[j + 1] = swap;
            }
        }
    }
    return;
}

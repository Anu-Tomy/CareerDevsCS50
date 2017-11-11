#include <cs50.h>
#include <stdio.h>
int binarysearch(int n, int array[], int s);
int main(void)
{
    int array[100], n, i, s;
    printf("Enter maximum no.of array elements: ");
    n = get_int();
    printf("Enter array elements: \n");
    for (i =0; i < n; i++)
    {
        array[i] = get_int();
    }
    printf("Enter element to search: ");
    s = get_int();
    bool result = binarysearch(n, array, s);
    if(result == 1)
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

    int binarysearch(int n, int array[], int s)
    {
        int start = 0, end = n-1, mid;
        while(start <= end)
        {
            mid = (start+end)/2;
            if(s == array[mid])
                return true;
            else if(s<array[mid])
                end = mid-1;
                else
                    start = mid + 1;
        }
        return false;

    }
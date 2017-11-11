#include <cs50.h>
#include <stdio.h>
bool linearsearch(int n, int array[], int s);
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
    bool result = linearsearch(n, array, s);
    if(result == 1)
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

    bool linearsearch(int n, int array[], int s)
    {
        int flag = 0,i;
        //return false if n is negative
        if(n < 0)
        {
            return false;
        }
        for (i = 0; i < n; i++)
        {
            if(array[i]== s)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            return true;
        }else
        {
            return false;
        }
    return -1;
    }
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int array[100], n, i, s, flag = 0;
    printf("Enter maximum no.of array elements: ");
    n = get_int();
    printf("Enter array elements: \n");
    for (i =0; i < n; i++)
    {
        array[i] = get_int();
    }
    printf("Enter element to search: ");
    s = get_int();
    for (i =0; i < n; i++)
    {
        if(array[i]== s)
        {
            printf("%d is found\n", s);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("%d is not found\n",s);
}

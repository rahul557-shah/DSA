//Minimum number of jumps to reach the end of a given array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int getMinJumps(struct Array arr)
{
    int maxR = arr.A[0];
    int step = arr.A[0];
    int jump = 1;
    if (arr.length == 1)
        return 0;
    else if (arr.A[0] == 0)
        return -1;
    else
    {
        for (int i = 1; i < arr.length; i++)
        {
            if (i == arr.length - 1)
                return jump;
            maxR = __max(maxR, arr.A[i] + i);
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= maxR)
                    return -1;
                step = maxR - i;
            }
        }
    }
}
int main()
{
    struct Array arr;
    int length, sum;
    printf("Enter the size of an array: ");
    scanf("%d", &length);
    arr.length = length;
    arr.A = (int *)malloc(arr.length * sizeof(int));
    printf("Enter the elements:");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("The Array is:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nMinimum Number of jumps is : %d", getMinJumps(arr));
    return 0;
}
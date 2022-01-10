//Find if there is subarray with sum equal to zero.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    int length;
    int *A;
};
//Time ->O(n^2)
bool Sum(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        int sum = 0;
        for (int j = i; j < arr.length; j++)
        {
            sum = sum + arr.A[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}
int main()
{
    struct Array arr;
    int length;
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
    if (Sum(arr))
        printf("\nYes");
    else
        printf("\nNo");
    return 0;
}
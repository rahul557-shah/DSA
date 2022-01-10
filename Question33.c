/*Find the minimum Distance between two numbers in an array*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Array
{
    int length;
    int *A;
};
//First Approach -> O(n^2)
int MinimumDist(struct Array arr, int x, int y)
{
    int mindis = INT_MAX;
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if ((x == arr.A[i] && y == arr.A[j] || y == arr.A[i] && x == arr.A[j]) && mindis > abs(i - j))
                mindis = abs(i - j);
        }
    }
    return mindis;
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
    printf("\nMinimum Distance is: %d", MinimumDist(arr, 3, 6));
    return 0;
}
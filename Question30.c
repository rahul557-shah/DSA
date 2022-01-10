/*Find the Equilibrium Point of a given array ie the sum of left elements and right elements must be equal*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
//First Approach -> O(n^2)
int Equilibrium(struct Array arr)
{
    int left, right;
    for (int i = 0; i < arr.length; i++)
    {
        left = 0;
        for (int j = 0; j < i; j++)
            left += arr.A[j];
        right = 0;
        for (int j = i + 1; j < arr.length; j++)
            right += arr.A[j];
        if (left == right)
            return i;
    }
    return -1;
}
//More Efficient Approach -> O(n)
int EquilibriumPoint(struct Array arr)
{
    int leftsum = 0, sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum - arr.A[i];
        if (leftsum == sum)
            return i;
        leftsum += arr.A[i];
    }
    return -1;
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
    printf("\nEqilibrium Point is : %d ", EquilibriumPoint(arr));
    return 0;
}
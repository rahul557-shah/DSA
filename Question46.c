// Count the pair equal to given sum
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
// Time->O(n^2)
// Space->O(1)
int Sum(struct Array arr, int sum)
{
    int count = 0;
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == sum)
                count++;
        }
    }
    return count;
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
    printf("\nEnter the sum to be checked: ");
    scanf("%d", &sum);
    printf("Count of Pairs is: %d ", Sum(arr, sum));
    return 0;
}
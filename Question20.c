//Find the triplet whose sum is 'sum' or zero
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
//Method-1 having Time->O(n^3)
int FindTriplet(struct Array arr, int sum)
{
    for (int i = 0; i < arr.length - 2; i++)
    {
        for (int j = i + 1; j < arr.length - 1; j++)
        {
            for (int k = j + 1; k < arr.length; k++)
            {
                if (arr.A[i] + arr.A[j] + arr.A[k] == sum)
                {
                    printf("%d, %d, %d", arr.A[i], arr.A[j], arr.A[k]);
                    return 1;
                }
            }
        }
    }
    return 0;
}
//Bubble Sort
void SortInAscending(struct Array arr)
{
    int temp;
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = 0; j < arr.length - 1 - i; j++)
        {
            if (arr.A[j] > arr.A[j + 1])
            {
                temp = arr.A[j];
                arr.A[j] = arr.A[j + 1];
                arr.A[j + 1] = temp;
            }
        }
    }
}
//Method-2 having Time->O(n^2)
int Triplet(struct Array arr, int sum)
{
    int l, r;
    SortInAscending(arr);
    for (int i = 0; i < arr.length - 1; i++)
    {
        l = i + 1;
        r = arr.length - 1;
        while (l < r)
        {
            if (arr.A[i] + arr.A[l] + arr.A[r] == sum)
            {
                printf("%d ,%d ,%d", arr.A[i], arr.A[l], arr.A[r]);
                return 1;
            }
            else if (arr.A[i] + arr.A[l] + arr.A[r] < sum)
                l++;
            else
                r--;
        }
    }
    return 0;
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
    int sum;
    printf("\nEnter the sum: ");
    scanf("%d",&sum);
    printf("\nTriplet Elements is:\n");
    Triplet(arr, sum);
    return 0;
}
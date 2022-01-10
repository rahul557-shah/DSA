/*Majority Element in an array*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Array
{
    int length;
    int *A;
};
//Time->O(n^2)
int Majority(struct Array arr)
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < arr.length; i++)
    {
        int count = 0;
        for (int j = 0; j < arr.length; j++)
        {
            if (arr.A[i] == arr.A[j])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    if (maxCount > arr.length / 2)
        return arr.A[index];
    return -1;
}
//Time->O(n)
int MajorityElement(struct Array arr)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (count == 0)
            candidate = arr.A[i];
        if (arr.A[i] == candidate)
            count++;
        else
            count--;
    }
    int c = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == candidate)
            c++;
    }
    if (c > arr.length / 2)
        return candidate;
    else
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
    printf("\nMajority Element is :%d", MajorityElement(arr));
    return 0;
}
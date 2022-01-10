//Remove duplicates from an array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
//Space is->O(1)
int RemoveDuplicates(struct Array arr)
{
    int j = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] != arr.A[i + 1])
        {
            arr.A[j] = arr.A[i];
            j++;
        }
    }
    arr.A[j] = arr.A[arr.length - 1];
    return j;
}
//Space->O(n)
int Remove(struct Array arr)
{
    int j = 0;
    int temp[10];
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] != arr.A[i + 1])
        {
            temp[j] = arr.A[i];
            j++;
        }
    }
    temp[j] = arr.A[arr.length - 1];
    for (int i = 0; i <= j; i++)
        arr.A[i] = temp[i];
    return j;
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
    printf("\nAfter Removing Duplicates:\n");
    int n = RemoveDuplicates(arr);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
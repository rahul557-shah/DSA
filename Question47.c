//MergeSort an Array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
void Merge(struct Array arr, int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int B[h+1];
    while (i <= mid && j <= h)
    {
        if (arr.A[i] < arr.A[j])
            B[k++] = arr.A[i++];
        else
            B[k++] = arr.A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = arr.A[i];
    for (; j <= h; j++)
        B[k++] = arr.A[j];
    for (i = l; i <= h; i++)
    {
        arr.A[i] = B[i];
    }
}
void RecursiveMergeSort(struct Array arr, int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        RecursiveMergeSort(arr, l, mid);
        RecursiveMergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
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
    printf("\nAfter Merging\n");
    RecursiveMergeSort(arr, 0, arr.length - 1);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
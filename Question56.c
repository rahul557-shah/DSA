//Count the inversions
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int Merge(struct Array arr, int B[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid;
    k = l;
    int inv = 0;
    while ((i <= mid - 1) && (j <= h))
    {
        if (arr.A[i] <= arr.A[j])
            B[k++] = arr.A[i++];
        else
        {
            B[k++] = arr.A[j++];
            inv += (mid - i);
        }
    }
    for (; i <= mid - 1; i++)
        B[k++] = arr.A[i];
    for (; j <= h; j++)
        B[k++] = arr.A[j];
    for (i = l; i <= h; i++)
    {
        arr.A[i] = B[i];
    }
    return inv;
}
int RecursiveMergeSort(struct Array arr, int B[], int l, int h)
{
    int mid, inv = 0;
    if (l < h)
    {
        mid = (l + h) / 2;
        inv += RecursiveMergeSort(arr, B, l, mid);
        inv += RecursiveMergeSort(arr, B, mid + 1, h);
        inv += Merge(arr, B, l, mid + 1, h);
    }
    return inv;
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
    int B[length];
    int ans = RecursiveMergeSort(arr, B, 0, arr.length - 1);
    printf("\nTotal Number of Inversions is: %d ", ans);
    return 0;
}
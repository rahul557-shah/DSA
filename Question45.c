//Find the kth Smallest element
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Partition(struct Array arr, int l, int h)
{
    int i = l;
    int j = h+1;
    int pivot = arr.A[l];
    do
    {
        do
        {
            i++;
        } while (arr.A[i] <= pivot);
        do
        {
            j--;
        } while (arr.A[j] > pivot);
        if (i < j)
            swap(&arr.A[i], &arr.A[j]);
    } while (i < j);
    swap(&arr.A[l], &arr.A[j]);
    return j;
}
void QuickSort(struct Array arr, int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j + 1, h);
    }
}
int KSmallest(struct Array arr, int l, int h, int k)
{
    QuickSort(arr, l, h);
    return arr.A[k - 1];
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
    int k;
    printf("\nEnter the value of k:");
    scanf("%d", &k);
    printf("Kth Smallest element is:\n");
    printf("%d ", KSmallest(arr, 0, arr.length - 1, k));
    return 0;
}
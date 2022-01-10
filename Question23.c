//Find the Peak Element in an Array ie, that element must be greater than both left and right element to it
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int PeakElement(struct Array arr)
{
    //If Peak Element is first or last
    if (arr.length == 1)
        return 0;
    if (arr.A[0] > arr.A[1])
        return 0;
    if (arr.A[arr.length - 1] > arr.A[arr.length - 2])
        return arr.length - 1;
    //If Peak Element is other than first of last
    for (int i = 1; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1] && arr.A[i] > arr.A[i - 1])
            return i;
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
    printf("\nPeak element is at %d ", PeakElement(arr));
    return 0;
}
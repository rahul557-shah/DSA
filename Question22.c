//Find the transistion point of a binary array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
//Simply by traversing the array
int Transistion(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == 1)
            return i;
    }
    return -1;
}
//Using Binary Search
int TransistionPoint(struct Array arr)
{
    int l = 0, h = arr.length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == 0)
            l = mid + 1;
        else if (arr.A[mid] == 1)
        {
            if (mid >= 0 && arr.A[mid - 1] == 0)
                return mid;
            h = mid - 1;
        }
    }
    return -1;
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
    printf("\nThe transistion point of the array is : %d", TransistionPoint(arr));
    return 0;
}
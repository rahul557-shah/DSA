//Move all the negative elements to one side
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
//Time->O(n)
void NegativeToOneSide(struct Array arr)
{
    int l = 0;
    int h = arr.length - 1;
    while (l <= h)
    {
        if (arr.A[l] > 0)
        {
            swap(&arr.A[l], &arr.A[h]);
            h--;
        }
        else
            l++;
    }
}
//Time->O(n)
void rearrange(struct Array arr)
{
    int j = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < 0)
        {
            if (i != j)
                swap(&arr.A[i], &arr.A[j]);
            j++;
        }
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
    rearrange(arr);
    printf("\nAfter Rearranging:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
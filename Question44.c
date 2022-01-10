//Move all the negative numbers to the last of the list
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
//Space ->O(1)
void NegativeToLast(struct Array arr)
{

    int l = 0;
    int h = arr.length - 1;
    while (l < h)
    {
        if (arr.A[l] < 0)
        {
            swap(&arr.A[l], &arr.A[h]);
            h--;
        }
        else
            l++;
    }
}
//Space->O(n)
void NegativeNumToLast(struct Array arr)
{
    int temp[arr.length];
    int j = 0;
    for (int i = 0; i < arr.length; i++) //Traversing for  positive elements
    {
        if (arr.A[i] >= 0)
        {
            temp[j] = arr.A[i];
            j++;
        }
    }
    if (j == arr.length || j == 0)
        return;

    for (int i = 0; i < arr.length; i++) //Traversing for Negative Elements
    {
        if (arr.A[i] < 0)
        {
            temp[j] = arr.A[i];
            j++;
        }
    }
    for (int i = 0; i < arr.length; i++) //Copying from temp array to original array
    {
        arr.A[i] = temp[i];
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
    printf("\nAfter Moving Negative to last, Array is\n");
    NegativeToLast(arr);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
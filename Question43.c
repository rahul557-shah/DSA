//Sort an array of 0s,1s,2s
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
void Sort012(struct Array arr)
{
    int l, h, mid;
    l = mid = 0;
    h = arr.length - 1;
    while (mid <= h)
    {
        switch (arr.A[mid])
        {
        case 0:
            swap(&arr.A[l], &arr.A[mid]);
            l++;
            mid++;
            break;

        case 1:
            mid++;
            break;
        case 2:
            swap(&arr.A[mid], &arr.A[h]);
            h--;
            break;
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
    Sort012(arr);
    printf("\nAfter Sorting\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
//Find maximum product subarray
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
int Maxproduct(struct Array arr)
{
    int max, min, product;
    max = min = product = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < 0)
            swap(&max, &min);
        max = __max(arr.A[i], arr.A[i] * max);
        min = __min(arr.A[i], arr.A[i] * min);
        if (product < max)
            product = max;
    }
    return product;
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
    printf("\nMaximum Product is: %d ", Maxproduct(arr));
    return 0;
}
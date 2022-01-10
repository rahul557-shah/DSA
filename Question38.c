/*Rotate an Array by certain position*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Array
{
    int length;
    int *A;
};
void RotateByOne(struct Array arr)
{
    int temp = arr.A[0];
    for (int i = 0; i < arr.length - 1; i++)
    {
        arr.A[i] = arr.A[i + 1];
    }
    arr.A[arr.length - 1] = temp;
}
void Rotate(struct Array arr, int d)
{
    for (int i = 0; i < d; i++)
    {
        RotateByOne(arr); //Recurrsive Call
    }
}
int main()
{
    int d;
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
    printf("\nEnter the number of place to be rotated:");
    scanf("%d", &d);
    printf("After Rotation\n");
    Rotate(arr, d);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
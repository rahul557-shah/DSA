/*Takes an input array of numbers and return a new array, sorted in ascending order (smallest to biggest).

  If the function's argument is null, an empty array, or undefined; return an empty array.
 
  Examples
    [1, 2, 10, 50, 5] ➞ [1, 2, 5, 10, 50]

    [80, 29, 4, -95, -24, 85] ➞ [-95, -24, 4, 29, 80, 85]

    [] ➞ []*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int SortArray(struct Array arr)
{
    int temp;
    if (arr.length == 0)
        printf("[]");
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = 0; j < arr.length - i - 1; j++)
        {
            if (arr.A[j] > arr.A[j + 1])
            {
                temp = arr.A[j];
                arr.A[j] = arr.A[j + 1];
                arr.A[j + 1] = temp;
            }
        }
    }
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
    SortArray(arr);
    printf("\nThe Sorted Array is:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    return 0;
}
/*Add 1 to every element in the given array.
  Examples
  [0, 1, 2, 3] ➞ [1, 2, 3, 4]
  [2, 4, 6, 8] ➞ [3, 5, 7, 9]
  [-1, -2, -3, -4] ➞ [0, -1, -2, -3]*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
void AddOne(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i] + 1);
    }
}
int main()
{
    struct Array arr;
    int length;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    arr.length = length;
    arr.A = (int *)malloc(arr.length * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    printf("The Array List is: \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nThe Result After Adding One is:\n");
    AddOne(arr);
    return 0;
}

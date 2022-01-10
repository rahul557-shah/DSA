/* Take input, an array of positive and negative numbers. Return an array where the first element is the count of positive numbers and the second element is the sum of negative numbers.

  Examples
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15] ➞ [10, -65]
    There are a total of 10 positive numbers.
    The sum of all negative numbers equals -65.

    [92, 6, 73, -77, 81, -90, 99, 8, -85, 34] ➞ [7, -252]
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    int length;
    int *A;
};
void PositiveNegative(struct Array arr)
{

    int pos = 0, neg = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > 0)
            pos++;
        else if (arr.A[i] < 0)
            neg += arr.A[i];
    }
    int res[2] = {pos, neg};
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", res[i]);
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
    printf("\nThe Resultant Array is\n");
    PositiveNegative(arr);
    return 0;
}
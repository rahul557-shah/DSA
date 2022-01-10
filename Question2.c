/* Given an array of integers, determine whether the sum of its elements is even or odd. The output should be a string ("odd" or "even").
  If the input array is empty, consider it as an array with a zero ([0]).
  Examples
    evenOrOdd([0]) ➞ "even"
    evenOrOdd([1]) ➞ "odd"
    evenOrOdd([]) ➞ "even"
    evenOrOdd([0, 1, 5]) ➞ "even"*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}
void Find(struct Array arr)
{
    if (Sum(arr) % 2 == 0)
        printf("Even");
    else
        printf("Odd");
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
    printf("\nThe Array is:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nSum is: %d\n", Sum(arr));
    Find(arr);
    return 0;
}
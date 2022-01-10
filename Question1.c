/*Take an input, array of numbers and return only the even values.
  Examples
    [1, 2, 3, 4, 5, 6, 7, 8] ➞ [2, 4, 6, 8]
    [43, 65, 23, 89, 53, 9, 6] ➞ [6]
    [718, 991, 449, 644, 380, 440] ➞ [718, 644, 380, 440]
  
  Notes
    Return all even numbers in the order they were given.
    All test cases contain valid numbers ranging from 1 to 3000.*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int EvenElements(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] % 2 == 0)
            printf("%d ", arr.A[i]);
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
    printf("\nThe List of Even Elements is:\n");
    EvenElements(arr);
    return 0;
}

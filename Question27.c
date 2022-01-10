/*Write a program that takes an array of numbers arr and a number n. Return true if the sum of any two elements is equal to the given number. Otherwise, return false.

  Examples
    ([10, 12, 4, 7, 9, 11], 16) ➞ true

    ([4, 5, 6, 7, 8, 9], 13) ➞ true

    ([0, 98, 76, 23], 174) ➞ true

    ([0, 9, 7, 23, 19, 18, 17, 66], 39) ➞ false*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    int length;
    int *A;
};
void SortInAscending(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] > arr.A[j])
            {
                int temp = arr.A[i];
                arr.A[i] = arr.A[j];
                arr.A[j] = temp;
            }
        }
    }
}
bool Check(struct Array arr, int sum)
{
    SortInAscending(arr);
    int l = 0;
    int r = arr.length - 1;
    SortInAscending(arr);
    while (l < r)
    {
        if (arr.A[l] + arr.A[r] == sum)
        {
            //printf("\nThe indexes are :%d %d", l, r);
            return 1;
        }

        else if (arr.A[l] + arr.A[r] < sum)
            l++;
        else
            r--;
    }
    return 0;
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
    printf("\nEnter the sum to be checked:");
    scanf("%d", &sum);
    if (Check(arr, sum))
        printf("True");
    else
        printf("False");
    return 0;
}
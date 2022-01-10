/*Write a program that takes two numbers as arguments (num, length) and returns an array of multiples of num until the array length reaches length.

  Examples
    arrayOfMultiples(7, 5) ➞ [7, 14, 21, 28, 35]*/
#include <stdio.h>
void Multiples(int A[], int n, int length)
{
    int res = 0;
    for (int i = 1; i <= length; i++)
    {
        res = n * i;
        A[i] = res;
        printf("%d ", A[i]);
    }
}
int main()
{
    int A[10];
    int n, length;
    printf("Enter the number and length: ");
    scanf("%d%d", &n, &length);
    printf("Array of Multiples is:\n");
    Multiples(A, n, length);
    return 0;
}

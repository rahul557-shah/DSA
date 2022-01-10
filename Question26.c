/*Write a program that returns the sum of all even elements in a 2D matrix.
  Examples
    [
      [1, 0, 2],
      [5, 5, 7],
      [9, 4, 3]
    ] ➞ 6
    // 2 + 4 = 6

    [
      [1, 1],
      [1, 1]
    ] ➞ 0*/
#include <stdio.h>
int main()
{
    int m, n, sum = 0;
    int A[10][10];
    printf("Enter rows and columns:");
    scanf("%d%d", &m, &n);
    printf("Enter the elements:");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("The 2D array is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] % 2 == 0)
                sum += A[i][j];
        }
    }
    printf("The Sum of all Elements is : %d", sum);
    return 0;
}
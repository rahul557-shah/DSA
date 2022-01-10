/*Suppose an image can be represented as a 2D array of 0s and 1s. Write a function to reverse an image. Replace the 0s with 1s and vice versa.

  Examples
    ([
      [1, 0, 0],
      [0, 1, 0],
      [0, 0, 1]
    ]) ➞ [
      [0, 1, 1],
      [1, 0, 1],
      [1, 1, 0]
    ]*/
#include <stdio.h>
int main()
{
    int A[10][10];
    int m, n;
    printf("Enter the rows and columns: ");
    scanf("%d%d", &m, &n);
    printf("Enter the elemnts: ");
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
            if (A[i][j] == 1)
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
    }
    printf("The 2D array after Interchanging:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
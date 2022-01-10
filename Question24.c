/*Count the number of 1s in a given 2D array.

  Examples
    [
      [1, 0],
      [0, 0]
    ] ➞ 1

    [
      [1, 1, 1],
      [0, 0, 1],
      [1, 1, 1]
    ] ➞ 7*/
//Find the Peak Element in an Array
#include <stdio.h>
int main()
{
    int m, n, count = 0;
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
            if (A[i][j] == 1)
                count++;
        }
    }
    printf("The number of one is : %d", count);
    return 0;
}
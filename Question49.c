//Union of two sorted Array
#include <stdio.h>
void Union(int A[], int B[], int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int C[m + n];
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] > B[j])
        {
            C[k] = B[j];
            k++;
            j++;
        }
        else
        {
            C[k] = A[i];
            k++;
            i++;
            j++;
        }
    }
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < n)
    {
        C[k] = B[j];
        j++;
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", C[i]);
    }
}
int main()
{
    int m, n;
    printf("Enter the size of both arrays: ");
    scanf("%d%d", &m, &n);
    int A[m], B[n];
    printf("Enter the elements:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("The First Array is:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nEnter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    printf("The Second Array is:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\nThe Union of two Arrays is\n");
    Union(A, B, m, n);
    return 0;
}
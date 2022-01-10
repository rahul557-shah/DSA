//Merge two sorted Arrays without using an extra space
#include <stdio.h>
//Time ->O(m*n)
void Merge(int a[], int b[], int m, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int j, last = a[m - 1];
        for (j = m - 2; j >= 0 && a[j] > b[i]; j--)
        {
            a[j + 1] = a[j];
        }
        if (j != m - 2 || last > b[i])
        {
            a[j + 1] = b[i];
            b[i] = last;
        }
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}
//Time->O(m+n)
void MergeEfficient(int a[], int b[], int m, int n)
{
    int i = 0, j = 0, k = m - 1;
    while (i <= k && j < m)
    {
        if (a[i] < b[j])
            i++;
        else
        {
            swap(&a[k], &b[j]);
            k--;
            j++;
        }
    }
    Sort(a, m);
    Sort(b, n);
}
int main()
{
    int len1, len2;
    int A[10], B[10];
    printf("Enter the length of first array: ");
    scanf("%d", &len1);
    printf("Enter the elements in first array\n");
    for (int i = 0; i < len1; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("First Array is: ");
    for (int i = 0; i < len1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nEnter the length of second array: ");
    scanf("%d", &len2);
    printf("Enter the elements in second array\n");
    for (int i = 0; i < len2; i++)
    {
        scanf("%d", &B[i]);
    }
    printf("Second Array is: ");
    for (int i = 0; i < len2; i++)
    {
        printf("%d ", B[i]);
    }
    MergeEfficient(A, B, len1, len2);
    printf("\nAfter Merging:\n");
    printf("First Array is: ");
    for (int i = 0; i < len1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nSecond Array is: ");
    for (int i = 0; i < len2; i++)
    {
        printf("%d ", B[i]);
    }
    return 0;
}
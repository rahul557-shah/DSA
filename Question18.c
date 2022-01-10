//Find the dulicates in an array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int FindDuplicates(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
                printf("%d occurs : %d times \n", arr.A[i], count);
        }
    }
    return -1;
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
    printf("\n");
    FindDuplicates(arr);
    return 0;
}
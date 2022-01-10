//Remove single Duplicate in an unsorted array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
int Duplicates(struct Array arr)
{
    int slow, fast;
    slow = fast = arr.A[0];
    do
    {
        slow = arr.A[slow];
        fast = arr.A[arr.A[fast]];
    } while (slow != fast);
    fast = arr.A[0];
    while (slow != fast)
    {
        slow = arr.A[slow];
        fast = arr.A[fast];
    }
    return slow;
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
    printf("\nThe Duplicate Number is: %d", Duplicates(arr));
    return 0;
}
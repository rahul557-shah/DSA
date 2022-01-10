//Kadane's Algo
/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
  Examples:
  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.
  Input: nums = [1]
  Output: 1
  Input: nums = [5,4,-1,7,8]
  Output: 23*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int length;
    int *A;
};
//Kadane's Algorithm
int LargestSum(struct Array arr)
{
    int current = 0, max = 0;
    for (int i = 0; i < arr.length; i++)
    {
        current += arr.A[i];
        if (current < 0)
            current = 0;
        if (max < current)
            max = current;
    }
    return max;
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
    printf("\nLargest Sum is: %d", LargestSum(arr));
    return 0;
}
//Check whether a String is Palindrome or not
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    int length;
    char *A;
};
bool IsPalindrome(struct Array arr)
{
    int l = 0;
    int h = arr.length - 1;
    while (h > l)
    {
        if (arr.A[l] != arr.A[h])
            return false;
        l++;
        h--;
    }
    return true;
}
int main()
{
    struct Array arr1;
    int length1;
    printf("Enter the size of string: ");
    scanf("%d", &length1);
    arr1.length = length1;
    arr1.A = (char *)malloc(arr1.length * sizeof(char));
    printf("Enter the elements:");
    for (int i = 0; i < arr1.length; i++)
    {
        scanf("%s", &arr1.A[i]);
    }
    printf("The String is:\n");
    for (int i = 0; i < arr1.length; i++)
    {
        printf("%c", arr1.A[i]);
    }
    printf("\n");
    if (IsPalindrome(arr1))
        printf("The String is Palindrome!!");
    else
        printf("The String isnot a palindrome!!");
    return 0;
}
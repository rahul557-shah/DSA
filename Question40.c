//Check for Anagram for two strings
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    int length;
    char *A;
};
bool IsAnagram(struct Array arr1, struct Array arr2)
{
    int count1[26] = {0};
    int count2[26] = {0};
    int i;
    for (i = 0; arr1.A[i] != '\0' && arr2.A[i] != '\0'; i++)
    {
        count1[arr1.A[i] - 97]++;
        count2[arr2.A[i] - 97]++;
    }
    if (arr1.A[i] != '\0' || arr2.A[i] != '\0')
        return false;
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}
int main()
{
    struct Array arr1, arr2;
    int length1,length2, sum;
    printf("Enter the size of string1: ");
    scanf("%d", &length1);
    printf("Enter the size of string2: ");
    scanf("%d", &length2);
    arr1.length = length1;
    arr2.length = length2;
    arr1.A = (char *)malloc(arr1.length * sizeof(char));
    arr2.A = (char *)malloc(arr2.length * sizeof(char));
    printf("Enter the elements:");
    for (int i = 0; i < arr1.length; i++)
    {
        scanf("%s", &arr1.A[i]);
    }
    printf("The First String is:\n");
    for (int i = 0; i < arr1.length; i++)
    {
        printf("%c", arr1.A[i]);
    }
    printf("\nEnter the elements:");
    for (int i = 0; i < arr2.length; i++)
    {
        scanf("%s", &arr2.A[i]);
    }
    printf("The Second String is:\n");
    for (int i = 0; i < arr2.length; i++)
    {
        printf("%c", arr2.A[i]);
    }
    printf("\n");
    if (IsAnagram(arr1, arr2))
        printf("They are anagram!!");
    else
        printf("Not anagram!!");
    return 0;
}
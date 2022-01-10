/*Write a program that returns the mean of all digits.
  Examples
    (42) ➞ 3

    (12345) ➞ 3

    (666) ➞ 6*/
#include <stdio.h>
int main()
{
    int n, rem, sum = 0, count = 0, mean;
    printf("Enter a number:");
    scanf("%d", &n);
    while (n > 0)
    {
        rem = n % 10;
        count++;
        sum += rem;
        n = n / 10;
    }
    mean = sum / count;
    printf("Mean of the number is:\n");
    printf("%d", mean);
    return 0;
}
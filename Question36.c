//Replace 0's with 5 of a given number
#include <stdio.h>
int Replace(int n)
{
    if (n == 0)
        return 0;
    int digit = n % 10;
    if (digit == 0)
        digit = 5;
    return Replace(n / 10) * 10 + digit;
}
int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    printf("After Replacing\n");
    printf("%d", Replace(num));
    return 0;
}
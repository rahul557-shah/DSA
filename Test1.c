#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int roll;
    char name[30];
    int *marks;
};
void display(struct Student stud)
{
    printf("roll is: %d", stud.roll);
    printf("Name: %s ", stud.name);
    for (int i = 0; i < 3; i++)
        printf("%d", stud.marks[i]);
}
int main()
{
    struct Student stud1,stud2;
    printf("Enter the roll");
    scanf("%d", &stud1.roll);
    printf("Enter the name: ");
    scanf("%s", &stud1.name);
    stud1.marks = (int *)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
        scanf("%d", &stud1.marks[i]);
    display(stud1);
    printf("Enter the roll");
    scanf("%d", &stud2.roll);
    printf("Enter the name: ");
    scanf("%s", &stud2.name);
    stud2.marks = (int *)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
        scanf("%d", &stud2.marks[i]);
    display(stud2);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char name[30];
    int roll;
    int marks[3];
} s;

int main()
{

    struct Student studentDetails[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the information for student %d:\n", i);
        fflush(stdin);
        printf("Enter name\n");
        fgets(studentDetails[i].name, 50, stdin);
        printf("Enter roll\n");
        scanf("%d", &studentDetails[i].roll);
        printf("Enter marks for 5 subjects\n");
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &studentDetails[i].marks[j]);
        }
    }

    //display
    for (int i = 0; i < 5; i++)
    {
        printf("name = %s\n", studentDetails[i].name);
        printf("roll = %d\n", studentDetails[i].roll);
        printf("Subjects for 5 subject marks:\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", studentDetails[i].marks[j]);
        }
        printf("\n");
    }
    return 0;
}
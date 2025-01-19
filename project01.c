#include <stdio.h>
#include <string.h>

struct user
{
    char name[20];
    int roll_no;
    char stream[30];
};

void add_student(struct user student[], int *count);
void searchbyrollno(struct user student[], int count);
void searchbystream(struct user student[], int count);
void showstudent(struct user student[], int count);

int main()
{

    struct user student[200];
    int count = 0;
    int choose;

    while (1)
    {
        printf(" \n");

        printf("press (1) add a student \n");
        printf("press (2) search student by stream \n");
        printf("press (3) search student by roll no \n");
        printf("press (4) show all students \n");
        printf("press (0) exit \n\n");
        printf("choose one option ");
        scanf("%d", &choose);
        printf(" \n");

        switch (choose)
        {
        case 1:
            add_student(student, &count);
            printf(" \n");
            break;

        case 2:
            searchbystream(student, count);
            break;

        case 3:
            searchbyrollno(student, count);
            break;

        case 4:
            showstudent(student, count);
            break;

        case 0:
            printf(" .... exiting ....\n \n");
            return 0;

        default:
            printf("invalid option .... try again \n \n");
        }
    }
}

void add_student(struct user student[], int *count)
{
    int n;
    printf("how many students you want to add : \n");
    scanf("%d", &n);
    printf(" \n");

    for (int i = *count; i < n + *count; i++)
    {
        printf("enter student name \n");
        scanf("%s", &student[i].name);
        printf("enter student roll no: \n");
        scanf("%d", &student[i].roll_no);
        printf("enter students stream: \n");
        scanf("%s", &student[i].stream);
        printf(" \n");
    }

    *count += n;

    for (int i = *count - n; i < *count; i++)
    {
        printf("student name: %s \n", student[i].name);

        printf("student roll no: %d \n", student[i].roll_no);

        printf("student stream: %s \n  \n", student[i].stream);
        printf(" \n");
    }
    printf(" \n");
    printf("********************************* \n");
    printf("students are successfully added \n \n");
    printf("%d students are in class \n", *count);
};

void searchbyrollno(struct user student[], int count)
{
    int number;
    printf("enter roll number \n");
    scanf("%d", &number);

    for (int i = 0; i <= count; i++)
    {

        if (student[i].roll_no == number)
        {
            printf("   ********************************* \n");
            printf(" roll no    student name     stream  \n");
            printf("  %d            %s          %s \n", student[i].roll_no, student[i].name, student[i].stream);
        }
    }
};

void showstudent(struct user student[], int count)
{
    if (count == 0)
    {
        printf("no students in list \n");
    }
    else
    printf("list of all students : \n \n");
    printf("********************** \n");
    printf("roll no   student name    stream \n");
    for (int i = 0; i < count; i++)
    {
        printf("  %d       %s         %s \n", student[i].roll_no, student[i].name, student[i].stream);
    }
};

void searchbystream(struct user student[], int count)
{
    char st[100];
    printf("enter stream \n");
    scanf("%s", &st);
    if (count == 0)
    {
        printf("This stream is not available \n");
    }

    printf("   ********************************* \n");
    printf(" roll no    student name     stream  \n");

    for (int i = 0; i <= count; i++)
    {
        if (strcmp(student[i].stream, st) == 0)
        {
            printf("  %d            %s          %s \n", student[i].roll_no, student[i].name, student[i].stream);
        }
    }
};

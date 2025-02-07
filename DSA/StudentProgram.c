#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[30];
    int reg_no;
    int marks[3];
    float avg;
} Student;
Student *read(int n)
{
    Student *st = (Student *)malloc(n * sizeof(Student));
    if (st == NULL)
    {
        printf("Memory Allocation Failed ");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Information Student : %d \n", (i + 1));
        printf("Name : ");
        scanf("%s", st[i].name);
        printf("Register Number : ");
        scanf("%d", &st[i].reg_no);
        printf("Marks for Test : ");
        for (int j = 0; j < 3; j++)
        {
            printf("Test - %d : ", (j + 1));
            scanf("%d", &st[i].marks[j]);
        }
    }
    return st;
}
void display(Student *st, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" Information of Student : %d \n", (i + 1));
        printf("Name : %s\n", st[i].name);
        printf("Register Number : %d\n", st[i].reg_no);
        printf("Marks of Test : ");
        for (int j = 0; j < 3; j++)
        {
            printf("Test - %d : %d \n", (j + 1), st[i].marks[j]);
        }
    }
}
void calcAvg(Student *st, int n)
{
    int min = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        total = st[i].marks[0] + st[i].marks[1] + st[i].marks[2];
        min = (st[i].marks[0] < st[i].marks[1]) ? ((st[i].marks[0] < st[i].marks[2]) ? st[i].marks[0] : st[i].marks[2]) : ((st[i].marks[1] < st[i].marks[2]) ? st[i].marks[1] : st[i].marks[2]);
        st[i].avg = (total - min) / 2.0;
        printf("Average of Student with register number %d : %f \n", st[i].reg_no, st[i].avg);
    }
}

void sortReg(Student *st, int n)
{
    Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (st[j].reg_no > st[j + 1].reg_no)
            {
               temp=st[j];
               st[j]=st[j+1];
                st[j+1]=temp;
            }
        }
    }
}
void main()
{
    Student *st;
    int choice, n;
    printf("Enter Number of Students :");
    scanf("%d", &n);
    do
    {
        printf("Menu \n 1.Read Student Information \n 2.Display Student Information \n 3.Calculate Average of Student(Best of Two) \n 4.Sort According to Register Number \n 5.Exit \n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            st = read(n);
            break;
        case 2:
            display(st, n);
            break;
        case 3:
            calcAvg(st, n);
            break;
        case 4:
            sortReg(st, n);
            break;
        case 5:
            printf("Exiting ..");
            break;
        default:
            printf("Invalid Choice");
        }
    } while (choice != 5);
}

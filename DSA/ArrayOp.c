#include <stdio.h>
#include <stdlib.h>
int *read(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements into array : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return arr;
}
void display(int *arr, int n)
{
    printf("Array Elements :");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int *insertByPos(int *arr, int *n, int pos, int data)
{
    if (pos < 0 || pos > *n)
    {
        printf("Invalid Position ");
        return arr;
    }
    arr = (int *)realloc(arr, (*n + 1) * sizeof(int));
    for (int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = data;
    (*n)++;
    return arr;
}
int *sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}
int *insertByOrder(int *arr, int *n, int data)
{
    int i;
    arr = (int *)realloc(arr, (*n + 1) * sizeof(int));
    for (i = *n - 1; (i >= 0 && arr[i] > data); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = data;
    (*n)++;
    return arr;
}
int *deleteByPos(int *arr, int *n, int pos)
{
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid Position");
        return arr;
    }
    arr = (int *)realloc(arr, (*n - 1) * sizeof(int));
    for (int i = pos; i < *n; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return arr;
}
int *deleteByKey(int *arr, int *n, int data)
{
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] == data)
        {
            for (int j = i; j < *n; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr = (int *)realloc(arr, (*n - 1) * sizeof(int));
            (*n)--;
            return arr;
        }
    }
    return arr;
}
int searchByPos(int *arr, int n, int pos)
{
    if (pos < 0 || pos >= n)
    {
        printf("Invalid Position");
        return -1;
    }
    else
    {
        return arr[pos];
    }
}
void searchByKey(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at Position %d", arr[i], i);
            return;
        }
    }
    printf("%d Not found ", key);
}

void reverse(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main()
{
    int choice, pos, n, data;
    int *arr = NULL;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    arr = read(n);
    do
    {
        printf("\n Menu \n 1.Display \n 2.Insert By Position \n 3.Insert By Order \n 4.Delete By Position \n 5.Delete By Key \n 6.Search By Position \n 7.Search By Key \n 8.Reverse \n 9.Exit \n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(arr, n);
            break;
        case 2:
            printf("Enter Position : ");
            scanf("%d", &pos);
            printf("Enter Data : ");
            scanf("%d", &data);
            arr = insertByPos(arr, &n, pos, data);
            display(arr, n);
            break;
        case 3:
            printf("Enter Data : ");
            scanf("%d", &data);
            arr = sort(arr, n);
            arr = insertByOrder(arr, &n, data);
            display(arr, n);
            break;
        case 4:
            printf("Enter Position : ");
            scanf("%d", &pos);
            arr = deleteByPos(arr, &n, pos);
            display(arr, n);
            break;
        case 5:
            printf("Enter Data : ");
            scanf("%d", &data);
            arr = deleteByKey(arr, &n, data);
            display(arr, n);
            break;
        case 6:
            printf("Enter Position : ");
            scanf("%d", &pos);

            data = searchByPos(arr, n, pos);
            if (data != -1)
            {
                printf("Data at Position %d is %d", pos, data);
            }
            display(arr, n);
            break;
        case 7:
            printf("Enter Data : ");
            scanf("%d", &data);
            searchByKey(arr, n, data);
            display(arr, n);
            break;
        case 8:
            reverse(arr, n);
            display(arr, n);
            break;
        case 9:
            free(arr);
            printf("Exiting...");
            break;

        default:
            printf("Invalid Choice");
        }

    } while (choice != 9);
    return 0;
}

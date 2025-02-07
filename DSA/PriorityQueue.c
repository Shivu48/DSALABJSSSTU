#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
} PriorityQueue;
PriorityQueue *initializeQueue()
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (pq == NULL)
    {
        printf("Memory allocation failed ");
        return NULL;
    }
    pq->arr = (int *)malloc(sizeof(int));
    if (pq->arr == NULL)
    {
        printf("Memory allocation failed ");
        return NULL;
    }
    pq->size = 0;
    return pq;
}
void resize(PriorityQueue *pq)
{
    pq->arr = (int *)realloc(pq->arr, (pq->size + 1) * sizeof(int));
    if (pq->arr == NULL)
    {
        printf("Memory allocation failed ");
        return;
    }
}
void insert(PriorityQueue *pq, int val)
{
    resize(pq);
    pq->arr[pq->size] = val;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && pq->arr[i] > pq->arr[i - 1])
    {
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[i - 1];
        pq->arr[i - 1] = temp;
        i--;
    }
}
int extractMax(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("PriorityQueue is Empty ");
        return -1;
    }
    int val = pq->arr[0];
    for (int i = 1; i < pq->size; i++)
    {
        pq->arr[i - 1] = pq->arr[i];
    }
    pq->size--;
    return val;
}
int getMax(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("PriorityQueue is Empty ");
        return -1;
    }
    return pq->arr[0];
}
void display(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("PriorityQueue is Empty ");
        return;
    }
    printf("PriorityQueue :");
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d\t", pq->arr[i]);
    }
    printf("\n");
}
void freePQ(PriorityQueue *pq)
{
    free(pq->arr);
    free(pq);
}
int main()
{
    int choice, val;
    PriorityQueue *pq;
    pq = initializeQueue();
    do
    {
        printf("\n Menu \n 1.Insert Element \n 2.Extract Maximum Element \n 3.Get Maximum Element \n 4.Display  \n 5.Exit /n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value to Insert :");
            scanf("%d", &val);
            insert(pq, val);
            display(pq);
            break;
        case 2:
            val = extractMax(pq);
            if (val != -1)
            {
                printf("Extract Maximum Element : %d ", val);
                display(pq);
            }
            break;
        case 3:
            val = getMax(pq);
            if (val != -1)
            {
                printf("Maximum Element : %d ", val);
                display(pq);
            }
            break;
        case 4:
            display(pq);
            break;

        case 5:
            printf("Exiting ...");
            freePQ(pq);
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 5);
    return 0;
}

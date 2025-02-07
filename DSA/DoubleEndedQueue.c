#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memeory Allocation Failed ");
        exit(0);
    }
    q->arr = (int *)malloc(capacity * sizeof(int));
    if (q->arr == NULL)
    {
        printf("Memeory Allocation Failed ");
        exit(0);
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}
int isFull(Queue *q)
{
    return q->size == q->capacity;
}
int isEmpty(Queue *q)
{
    return q->size == 0;
}
void resizeQueue(Queue *q)
{
    int newCapacity = q->capacity * 2;
    int *newArr = (int *)malloc(newCapacity * sizeof(int));
    if (newArr == NULL)
    {
        printf("Memory Allocation Failed");
        exit(0);
    }
    
    for (int i = 0, j = q->front; i < q->size; i++)
    {
        newArr[i] = q->arr[j];
        j = (j + 1) % q->capacity;
    }
    
    free(q->arr);
    q->arr = newArr;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size - 1;
    
    printf("Queue resized to capacity %d\n", newCapacity);
}

void insertFront(Queue *q, int val)
{
    if (isFull(q))
    {
       resizeQueue(q);
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->front == 0)
    {
        q->front = q->capacity - 1;
    }
    else
    {
        q->front--;
    }
    q->arr[q->front] = val;
    q->size++;

    printf("Inserted %d ", val);
}
void insertRear(Queue *q, int val)
{
    if (isFull(q))
    {
      resizeQueue(q);
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->rear == q->capacity - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = val;
    q->size++;

    printf("Inserted %d ", val);
}
int deleteFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Double Ended Queue Underflow ");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->front == q->capacity - 1)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
    q->size--;
    printf("Dequeud %d ", val);
    return val;
}
int deleteRear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Double Ended Queue Underflow ");
        return -1;
    }
    int val = q->arr[q->rear];
    if (q->rear == q->front)
    {
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        q->rear = q->capacity - 1;
    }
    else
    {
        q->rear--;
    }
    q->size--;
    return val;
}
void display(Queue *q)
{

    if (isEmpty(q))
    {
        printf("Queue Underflow ");
        return;
    }
    printf("Queue : ");
    for (int i = q->front, count = 0; count < q->size; count++)
    {
        printf("%d\t", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main()
{
    int choice, val, capacity;
    printf("Enter the Capacity for Queue ");
    scanf("%d", &capacity);
    Queue *q = createQueue(capacity);
    do
    {
        printf(" \n Menu \n 1.EnQueue at front \n 2.EnQueue at Rear \n 3.DeQueue at Front \n 4.DeQueue at Rear  \n 5.Display \n 6.Exit \n");
        printf("Enter Your Choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value to enqueue at front :");
            scanf("%d", &val);
            insertFront(q, val);
            break;
        case 2:
            printf("enter value to enqueue  rear :");
            scanf("%d", &val);
            insertRear(q, val);
            break;
        case 3:
            val = deleteFront(q);
            if (val != -1)
            {
                printf(" DEQUEUED at front : %d", val);
            }
            break;
        case 4:

            val = deleteRear(q);
            if (val != -1)
            {
                printf(" DEQUEUED at rear : %d", val);
            }
            break;
        case 5:
            display(q);
            break;
        case 6:
            printf("Exiting ");
            break;
        default:
            printf("Invalid Choice ");
        }
    } while (choice != 6);
    return 0;
}

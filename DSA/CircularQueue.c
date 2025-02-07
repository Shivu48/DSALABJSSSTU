#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
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
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
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

int isFull(Queue *q)
{
    return q->size == q->capacity;
}
int isEmpty(Queue *q)
{
    return q->size == 0;
}
void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow ");
        return -1;
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
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
        printf(" \n Menu \n 1.EnQueue \n 2.DeQueue \n 3.Display \n 4.Exit \n");
        printf("Enter Your Choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value to enqueue :");
            scanf("%d", &val);
            enqueue(q, val);
            break;
        case 2:
            val = dequeue(q);
            if (val != -1)
            {
                printf(" DEQUEUED : %d", val);
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Exiting ");
            break;
        default:
            printf("Invalid Choice ");
        }
    } while (choice != 4);
    return 0;
}

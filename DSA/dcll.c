#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed ");
        return NULL;
    }
    return newNode;
}

Node *initializeHeader()
{
    Node *newNode = createNode(-1);
    newNode->next = newNode->prev = newNode;
    if (newNode == NULL)
    {
        printf("Memeory Allocation Failed ");
        return NULL;
    }
    return newNode;
}
void display(Node *head)
{
    if (head->next == head)
    {
        printf("List is Empty ");
        return;
    }
    Node *temp = head->next;
    printf("\n");
    while (temp != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertByOrder(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head->next == head)
    {
        printf("List is Empty Inserting at Front ");
        newNode->next = head;
        newNode->prev = head;
        head->next = newNode;
        head->prev = newNode;
        return;
    }
    Node *curr = head->next;
    while (curr != head && curr->data < data)
    {
        curr = curr->next;
    }

    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
}
void searchByKey(Node *head, int key)
{
    if (head->next == head)
    {
        printf("List is Empty ");
        return;
    }
    int pos = 0;
    Node *temp = head->next;
    while (temp != head && temp->data != key)
    {
        pos++;
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("key Not Found ");
        return;
    }
    printf("Key Found at Position %d\n", pos + 1);
}
void deleteByKey(Node *head, int key)
{
    if (head->next == head)
    {
        printf("List is Empty ");
        return;
    }
    Node *temp = head->next;
    while (temp != head && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("Key Doesnot Exist ");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void deleteByPos(Node *head, int pos)
{
    if (pos <= 0 || head->next == head)
    {
        printf("Either List is Empty or Invalid Position ");
        return;
    }
    Node *temp = head->next;
    if (pos == 1)
    {
        head->next = temp->next;
        temp->next->prev = head;
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp != head; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("Invald Position ");
        return;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}
void insertFront(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head->next == head)
    {
        newNode->next = head;
        newNode->prev = head;
        head->prev = newNode;
        head->next = newNode;
        return;
    }
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}
void insertRear(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
}
void insertByPos(Node *head, int data, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid Position ");
        return;
    }
    Node *newNode = createNode(data);

    if (pos == 1)
    {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        return;
    }
    Node *temp = head->next;
    for (int i = 1; i < pos - 1 && temp != head; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("Invalid Position");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteFront(Node *head)
{
    if (head->next == head)
    {
        printf("List is Empty");
        return;
    }
    Node *temp = head->next;
    head->next = temp->next;
    temp->prev = head;
    free(temp);
}
void deleteRear(Node *head)
{
    if (head->next == head)
    {
        printf("List is Empty");
        return;
    }
    Node *temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);
}

void searchByPos(Node *head, int pos)
{

    if (pos <= 0)
    {
        printf("Invalid Position ");
        return;
    }
    else if (head->next == head)
    {
        printf("List is Empty ");
    }
    Node *temp = head->next;
    for (int i = 1; i < pos && temp != head; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("Invalid Position ");
        return;
    }
    printf(" Value is %d at given position ", temp->data);
}
int main()
{
    int choice, pos, data;
    Node *head = initializeHeader();
    do
    {
        printf("\nMenu \n 1.Insert By Order  \n 2.Search By Order \n 3.Delete By Key \n 4.Delete By Position \n 5.Insert By Position \n 6.Insert Front \n 7.Insert Rear \n 8.Delete Front \n 9.Delete Front \n 10.Search By Position \n 11.Exit \n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert :");
            scanf("%d", &data);
            insertByOrder(head, data);
            display(head);
            break;
        case 2:
            printf("Enter Key to Search ");
            scanf("%d", &data);
            searchByKey(head, data);
            display(head);
            break;
        case 3:
            printf("Enter data to Delete By Key ");
            scanf("%d", &data);
            deleteByKey(head, data);
            display(head);
            break;
        case 4:
            printf("Enter Position to Delete ");
            scanf("%d", &pos);
            deleteByPos(head, pos);
            display(head);
            break;
        case 5:
            printf("Enter Data to Insert ");
            scanf("%d", &data);
            printf("Enter Position to Insert ");
            scanf("%d", &pos);
            insertByPos(head, data, pos);
            display(head);
            break;
        case 6:
            printf("Enter Data to Insert ");
            scanf("%d", &data);
            insertFront(head, data);
            display(head);

            break;
        case 7:
            printf("Enter Data to Insert ");
            scanf("%d", &data);
            insertRear(head, data);
            display(head);
            break;
        case 8:
            deleteFront(head);
            display(head);
            break;
        case 9:
            deleteRear(head);
            display(head);
            break;
        case 10:
            printf("Enter Position to Search ");
            scanf("%d", &pos);
            searchByPos(head, pos);
            display(head);
            break;
        case 11:
            printf("Exiting ");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 11);
    return 0;
}

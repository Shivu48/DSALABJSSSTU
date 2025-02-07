#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memeory allocation failed ");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(Node **head)
{
    if (*head == NULL)
    {
        printf("\n List  is Empty ");
        return;
    }
    Node *temp = *head;
    printf("\nList : ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertFront(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertRear(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        printf("List is Empty Inserted as First Node ");
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtPos(Node **head, int data, int pos)
{
    if (*head == NULL || pos <= 0)
    {
        printf("Invalid Position or List is Empty");
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position ");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertByOrder(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        printf("List was Empty . Inserted the new node in order ");
        return;
    }
    if ((*head)->data > data)
    {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at first ", data);
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d in Order", data);
}
void deleteFront(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty ");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteRear(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty ");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteByPos(Node **head, int pos)
{
    Node *temp = *head;
    Node *delete;

    if (head == NULL)
    {
        printf("List is Empty ");
        return;
    }
    else if (pos <= 0)
    {
        printf("Invalid Position ");
        return;
    }

    else if (pos == 1)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid Position ");
        return;
    }

    delete = temp->next;
    temp->next = delete->next;
    free(delete);
}
void search(Node **head, int key)
{
    Node *temp = (*head)->next;
    int pos = 1;
    if (*head == NULL)
    {
        printf("List is Empty ");
        return;
    }

    else if ((*head)->data == key)
    {

        printf("Key found at %d Position ", pos);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
        pos++;
    }
    if (temp == NULL)
    {
        printf("Key not found ");
        return;
    }
    printf("Key found at %d Position ", pos + 1);
}
void deleteByKey(Node **head, int key)
{
    Node *temp = *head;
    Node *delete;
    if (*head == NULL)
    {
        printf("List is empty ");
        return;
    }
    if ((*head)->data == key)
    {
        *head = (*head)->next;
        free(temp);
    }
    while (temp->next != NULL && temp->next->data != key)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf(" Key NOT FOUND ");
        return;
    }
    delete = temp->next;
    temp->next = delete->next;
    free(delete);
}
void searchByPos(Node **head, int pos)
{
    if (*head == NULL || pos <= 0)
    {
        printf("Invalid Position or List is Empty");
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position ");
        return;
    }
    printf("Key is %d at given Position ", temp->data);
}

int main()
{
    Node *head = NULL;
    int choice, data, pos;
    do
    {
        printf("\n Menu \n 1.Inserted By Order \n 2.Delete By Position \n 3.Search By Key \n 4.Delete By Key \n 5.Insert Front \n 6.Insert Rear \n 7.Insert By Position \n 8.Delete Front \n 9.Delete Rear \n 10 Search By Position \n 11.Exit \n");
        printf("Enter Your Choice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert By Order :");
            scanf("%d", &data);
            insertByOrder(&head, data);
            display(&head);
            break;
        case 2:
            printf("Enter Position to Delete Node :");
            scanf("%d", &pos);
            deleteByPos(&head, pos);
            display(&head);
            break;
        case 3:
            printf("Enter Key to Search Node :");
            scanf("%d", &data);
            search(&head, data);
            display(&head);
            break;
        case 4:
            printf("Enter Key to Delete Node :");
            scanf("%d", &data);
            deleteByKey(&head, data);
            display(&head);
            break;
        case 5:
            printf("Enter data to insert Front :");
            scanf("%d", &data);
            insertFront(&head, data);
            display(&head);
            break;
        case 6:
            printf("Enter data to insert Rear :");
            scanf("%d", &data);
            insertRear(&head, data);
            display(&head);
            break;
        case 7:
            printf("Enter data to insert By Position :");
            scanf("%d", &data);
            printf("Enter Position to insert Node :");
            scanf("%d", &pos);
            insertAtPos(&head, data, pos);
            display(&head);
            break;
        case 8:
            deleteFront(&head);
            display(&head);
            break;
        case 9:
            deleteRear(&head);
            display(&head);
            break;
        case 10:
            printf("Enter Position to Search Node :");
            scanf("%d", &pos);
            searchByPos(&head, pos);
            display(&head);
            break;
        case 11:
            printf("Exiting ...");
            break;
        default:
            printf("Invalid Choice !");
        }
    } while (choice != 11);
    return 0;
}

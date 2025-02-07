#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{

    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}
void bfs(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        Node *current = queue[front++];
        printf("%d\t", current->data);
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}
Node *search(Node *root, int key, Node **parent)
{
    *parent = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL && root->data != key)
    {
        *parent = root;
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(root!= NULL && root->data==key && * parent==NULL){
        *parent = NULL;
    }
    return root;
}
int countNode(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
Node *maxNode(Node *root, Node **parent)
{
    if (root == NULL)
    {
        return root;
    }
    *parent = NULL;
    while (root != NULL && root->right != NULL)
    {
        *parent = root;
        root = root->right;
    }
    return root;
}
Node *inOrderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{
    Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    Node *parent;
    Node *max;
    int choice, data;
    do
    {
        printf(" \n Menu \n 1.Insert Node(Construct Node) \n 2.DFS and BFS  \n 3.Searching a node by key  \n 4. Counting all nodes. \n 5.Finding height \n 6.Maximum of all node \n 7.Delete  a Node  with Key \n 8.Exit \n");
        printf("Enter Your Choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to Insert ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("IN ORDER TRAVERSAL     :       ");
            inOrder(root);
            printf("\n");
            printf("PRE ORDER TRAVERSAL     :      ");
            preOrder(root);
            printf("\n");
            printf("POST ORDER TRAVERSAL    :      ");
            postOrder(root);
            printf("\n");
            printf("BFS TRAVERSAL           :       ");
            bfs(root);
            printf("\n");
            break;
        case 3:
            printf("Enter Key to Search ");
            scanf("%d", &data);

            Node *searchNode = search(root, data, &parent);
            if (searchNode != NULL)
            {
                printf("Node Found ");
                if (parent != NULL)
                {
                    printf("Parent Node is %d", parent->data);
                }
                else
                {
                    printf("Parent Node is NULL");
                }
            }
            else
            {
                printf("Node Not Found ");
            }
            break;
        case 4:
            printf("Total Nodes are %d", countNode(root));

            break;
        case 5:
            printf("Height of Tree is %d", height(root));
            break;
        case 6:

            max = maxNode(root, &parent);
            if (max != NULL)
            {
                printf("Maximum Node is %d", max->data);
                if (parent != NULL)
                {
                    printf("Parent Node is %d", parent->data);
                }
                else
                {
                    printf("Parent Node is NULL");
                }
            }
            else
            {
                printf("Tree is Empty");
            }
            break;
        case 7:
            printf("Enter Key to Delete ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            if(root!=NULL){
                printf("Node Deleted");
            }
            else{
                printf("Node Not Found");
            }
            break;
        case 8:
            printf("Exiting ");
            break;
        default:
            printf("Invalid Choice");
        }
    } while (choice != 8);

    return 0;
}

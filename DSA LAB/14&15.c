#include <stdio.h>
#include <stdlib.h>
struct node
{
int item;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE getnode(int X)
{
NODE temp;
temp = (NODE)malloc(sizeof(struct node)); //Dynamically Allocating a new Node
temp->item = X;
temp->llink=temp->rlink=NULL;
return temp;
}
NODE insert(NODE root, int X)
{
NODE temp = getnode(X);
if(root==NULL)
return temp;
if(X<root->item)
root->llink = insert(root->llink,X);
else
root->rlink = insert(root->rlink,X);
return root;
}
void inorder(NODE root)
{
if(root!=NULL)
{
inorder(root->llink);
printf("%d\n",root->item);
inorder(root->rlink);
}
}
void preorder(NODE root)
{
if(root!=NULL)
{
printf("%d\n",root->item);
preorder(root->llink);
preorder(root->rlink);
}
}
void postorder(NODE root)
{
if(root!=NULL)
{
postorder(root->llink);
postorder(root->rlink);
printf("%d\n",root->item);
}
}
void main()
{
int choice,X;
NODE root=NULL;
printf("Menu\n1.Insert\n2.InOrder\n3.PreOrder\n4.PostOrder\n5.Exit\n");
for(;;)
{
printf("Enter Your Choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf("Enter an Element : ");
scanf("%d",&X);
root = insert(root,X);
break;
case 2 : inorder(root);
break;
case 3 : preorder(root);
break;
case 4 : postorder(root);
break;
case 5 : printf("!!THANK YOU!!\n");
exit(0);
default : printf("Invalid Choice\n");
}
}
}
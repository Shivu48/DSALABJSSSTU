#include <stdio.h>
#include <stdlib.h>
int size;
struct Stack{
int *stk; //Pointer to Array storing Stack
int top; //Index of Top of Stack
}S;
//Function to Push an Element into Stack
void push(int X)
{
//Checking if Stack is Full
if(S.top==size-1)
{
printf("Stack Overflow\n");
printf("Reallocating Memory\n");
size++;
//Reallocating Memory
S.stk=(int *)realloc(S.stk,size*sizeof(int));
}
S.top++;
*(S.stk+S.top)=X;
}
//Function to Pop an Element from Stack
void pop()
{
58
//Checking if Stack is Empty
if(S.top==-1)
printf("Stack UnderFlow\n");
else
{
printf("Deleted Element : %d\n",*(S.stk+S.top));
S.top--;
}
}
//Function to Display the top Element of Stack
void peek()
{
//Checking if Stack is Empty
if(S.top==-1)
printf("Stack UnderFlow\n");
else
printf("%d\n",*(S.stk+S.top));
}
//Function to Display all Elements of Stack
void display()
{
//Checking if Stack is Empty
if(S.top==-1)
printf("Stack UnderFlow\n");
else
{
printf("The Stack is :\n");
for(int i=S.top;i>=0;i--)
printf("%d\n",*(S.stk+i));
}
}
void main()
{
int choice,X;
printf("Enter the size of Stack : ");
scanf("%d",&size);
//Allocating Memory for the Stack Array
S.stk = (int *)calloc(size,sizeof(int));
S.top=-1; //Initializing Empty Stack
for(;;)
{
printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
printf("Enter Your Choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf("Enter the value to be pushed : ");
scanf("%d",&X);
push(X);
break;
59
case 2 : pop();
break;
case 3 : peek();
break;
case 4 : display();
break;
case 5 : printf("!! THANK YOU !!\n");
exit(0);
default : printf("Invalid Choice\n");
}
}
}
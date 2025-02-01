#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//Function to check Stack Precedence
int stackprec(char symbol)
{
switch(symbol)
{
case '+' :
case '-' : return 1;
case '*' :
case '/' :
case '%' : return 3;
case '^' :
case '$' : return 6;
case ')' : return 0;
case '#' : return -1;
default : return 8;
}
}
//Function to check Input Precedence
int inprec(char symbol)
{
switch(symbol)
{
case '+' :
case '-' : return 2;
case '*' :
case '/' :
case '%' : return 4;
case '^' :
case '$' : return 5;
case '(' : return 0;
case ')' : return 9;
default : return 7;
}
}
//Function to convert Infix to Prefix Expression
void infixtoprefix(char infix[], char prefix[])
{
char S[30]; //Stack to store the Expression
int i=0; //Index for Infix Expression
int j=0; //Index for Postfix Expression
int top=-1; //Initializing Empty Stack
S[++top] = '#';
char symbol;
strrev(infix);
for(i=0;i<strlen(infix);i++)
{
symbol = infix[i];
while(stackprec(S[top])>inprec(symbol))
{
prefix[j++]=S[top--];
}
if(stackprec(S[top])!=inprec(symbol))
{
S[++top] = symbol;
}
else
{
top--;
}
}
while(S[top]!='#')
{
prefix[j]=S[top--];
j++;
}
prefix[j]='\0';
strrev(prefix);
}
//Function to Evaluate Prefix Expression
void prefixevaluate(char prefix[])
{
int i,op1,op2,res;
strrev(prefix);
int Stack[10]; //Stack to store Operands
int top=-1; //Initializing Empty Stack
char ch;
for(i=0;i<strlen(prefix);i++)
{
ch = prefix[i];
if(isdigit(ch))
{
Stack[++top]=ch-'0'; //Pushing Operand into Stack
}
else
{
if(top<1)
printf("Not enough operands\n");
else
{
op1=Stack[top--]; //Popping Operand-1
op2=Stack[top--]; //Popping Operand-2
switch (ch)
{
case '+' : res = op1 + op2;
break;
case '-' : res = op1 - op2;
break;
case '/' : res = op1 / op2;
break;
case '*' : res = op1 * op2;
break;
case '%' : res = op1 % op2;
break;
default: printf("Invalid Operator\n");
}
Stack[++top] = res; //Pushing Result into Stack
}
}
}
printf("Final Result = %d\n",Stack[top]);
}
void main()
{
char infix[30]; //Array to store Infix Expression
char prefix[30]; //Array to store Prefix Expression
int choice;
printf("Menu\n1.Enter Infix Expression\n2.Convert to Prefix\n3.Evaluate prefix\n4.Exit\n");
for(;;)
{
printf("Enter Your Choice: ");
scanf("%d",&choice);
switch (choice)
{
case 1 : printf("Enter the Infix Expression : ");
scanf("%s",infix);
break;
case 2 : infixtoprefix(infix,prefix);
printf("The Prefix Expression is : ");
printf("%s\n",prefix);
break;
case 3 : prefixevaluate(prefix);
break;
case 4 : printf("!! THANK YOU !!\n");
exit(0);
default: printf("Invalid Choice\n");
}
}
}
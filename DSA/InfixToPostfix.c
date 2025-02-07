#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct
{
    int top;
    char arr[MAX];
} Stack;
typedef struct
{
    int top;
    int arr[MAX];
} evalStack;
void push(Stack *s, char val)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow ");
        return;
    }
    s->arr[++(s->top)] = val;
}
void evalPush(evalStack *s, int val)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow ");
        return;
    }
    s->arr[++(s->top)] = val;
}
char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow");
        return '\0';
    }
    return s->arr[(s->top)--];
}
int evalPop(evalStack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow");
        return '\0';
    }
    return s->arr[(s->top)--];
}
char peek(Stack *s)
{

    if (s->top == -1)
    {
        printf("Stack Underflow");
        return '\0';
    }
    return s->arr[s->top];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '%':
    case '/':
        return 2;
        break;
    case '^':
    case '$':
        return 3;
        break;
    default:
        return 0;
    }
}
void infixToPostfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    Stack s;
    s.top = -1;
    char ch;
    while (infix[i] != '\0')
    {
        ch = infix[i];
        if (isalpha(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (s.top != -1 && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (s.top != -1 && precedence(peek(&s)) > precedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
        i++;
    }
    while (s.top != -1)
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int evaluatePostfix(char *postfix)
{
    int op2, op1, i = 0;
    evalStack s;
    s.top = -1;
    char ch;
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            evalPush(&s, ch - '0');
        }
        else
        {
            op2 = evalPop(&s);
            op1 = evalPop(&s);
            switch (ch)
            {
            case '+':
                evalPush(&s, (op1 + op2));
                break;
            case '-':
                evalPush(&s, (op1 - op2));
                break;
            case '*':
                evalPush(&s, (op1 * op2));
                break;
            case '/':
                evalPush(&s, (op1 / op2));
                break;
            case '%':
                evalPush(&s, (op1 % op2));
                break;
            case '^':
                evalPush(&s, (pow(op1, op2)));
                break;
            }
        }
        i++;
    }
    return evalPop(&s);
}
int main()
{
    char postfix[MAX], infix[MAX];
    int choice;
    do
    {
        printf("\n Menu \n 1.Convert infix to Postfix \n 2. Evaluate Postfix \n 3.Exit \n ");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Infix Expression ");
            scanf("%s", infix);
            infixToPostfix(infix, postfix);
            printf("PostFix Expression : %s", postfix);
            break;

        case 2:
            printf("Enter Postfix Expression ");
            scanf("%s", postfix);
            int val = evaluatePostfix(postfix);
            printf("Evaluated Value : %d", val);
            break;
        case 3:
            printf("Exiting ");
            break;
        default:
            printf("Invalid Choice ");
        }
    } while (choice != 3);
    return 0;
}

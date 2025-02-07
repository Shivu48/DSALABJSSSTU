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

int  evalPop(evalStack *s)
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
void reverse(char *infix)
{
    int n = strlen(infix);
    for (int i = 0; i < n / 2; i++)
    {
        int temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }
}
void reverseParams(char *infix)
{
    int i = 0;
    while (infix[i++] != '\0')
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    int i = 0, j = 0;
    Stack s;
    s.top = -1;
    char ch;
    reverse(infix);
    reverseParams(infix);
    while (infix[i] != '\0')
    {
        ch = infix[i];
        if (isalpha(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (s.top != -1 && peek(&s) != '(')
            {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (s.top != -1 && precedence(peek(&s)) > precedence(ch))
            {
                prefix[j++] = pop(&s);
            }
            push(&s, ch);
        }
        i++;
    }
    while (s.top != -1)
    {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int evaluatePrefix(char *prefix)
{
    int op2, op1;
    evalStack s;
    s.top = -1;
    char ch;

    int n = strlen(prefix);
    for (int i = n - 1; i >= 0; i--)
    {
        ch = prefix[i];
        if (isdigit(ch))
        {
             evalPush(&s, ch - '0');
        }
        else
        {
            op1 = evalPop(&s);
            op2 = evalPop(&s);
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
    }
    return evalPop(&s);
}
int main()
{
    char prefix[MAX], infix[MAX];
    int choice;
    do
    {
        printf("\n Menu \n 1.Convert infix to prefix \n 2. Evaluate prefix \n 3.Exit \n ");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Infix Expression ");
            scanf("%s", infix);
            infixToPrefix(infix, prefix);
            printf("prefix Expression : %s", prefix);
            break;

        case 2:
            printf("Enter prefix Expression ");
            scanf("%s", prefix);
            int val = evaluatePrefix(prefix);
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

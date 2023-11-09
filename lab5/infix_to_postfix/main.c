#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
 int items[MAX_SIZE];
 int top;
};
void initialize(struct Stack *stack) {
 stack->top = -1;
}
_Bool isEmpty(struct Stack *stack) {
 return stack->top == -1;
}

_Bool isFull(struct Stack *stack) {
 return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, int item) {
 if (isFull(stack)) {
 printf("Stack overflow, cannot push %d\n", item);
 return;
 }
 stack->top++;
 stack->items[stack->top] = item;
}
int pop(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack underflow, cannot pop\n");
 return -1;
 }
 int poppedItem = stack->items[stack->top];
 stack->top--;
 return poppedItem;
}
int peek(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty, cannot peek\n");
 return -1;
 }
 return stack->items[stack->top];
}
int isoperator(char s)
{
    if(s=='+'||'-'||'*'||'/'||'^')
        return(1);
}
int precedence(char x)
{
    if(x=='+'||'-')
        return(1);
    else if(x=='*'||'/')
        return(2);
    else if(x=='^')
        return(3);

}
void intopostfix(char x)
{
    char postfix[100];
    int j=0;
    postfix[j++]=x;
}
void main()
{
    struct Stack stack;

    initialize(&stack);
    char infix[100],postfix[100];
    printf("enter infix operation");
    gets(infix);
    int i,l=strlen(infix);
    for(i=0;i<l;i++)
    {
        if(isoperator(infix[i])!=1)
       intopostfix(infix[i]);
        else if(infix[i]=='(')
        push(&stack,infix[i]);
        else if(infix[i]==')')
        {
            while(peek(&stack)!='(')
            {
                intopostfix(pop(&stack));
            }
        }
        else if(isoperator(infix[i])==1)
        {
            if(precedence(peek(&stack))>=precedence(infix[i]))
                push(&stack,infix[i]);
            else
            {
                while(precedence(peek(&stack))<precedence(infix[i]))
                {
                    intopostfix(pop(&stack));
                }
                push(&stack,infix[i]);
            }
        }
    }
    while(pop(&stack)!='/0')
    {
        intopostfix(pop(&stack));
    }
    puts(postfix);
}



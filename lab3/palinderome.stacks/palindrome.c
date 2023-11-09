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
int main()
{
    struct Stack stack;
    initialize(&stack);
    char s2[100];
    int i;

    printf("enter the number");
    gets(s2);
    int l=strlen(s2);
    for(i=0;i<l;i++)
    {
        push(&stack,s2[i]);
    }
    for(i=0;i<l;i++)
    {
        if(pop(&stack)!=s2[i])
        {


            printf("not a palindrome");
            return(0);}

    }
    printf("is a palindrome");
    return(0);
}

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
void main()
{
    struct Stack stack;
    initialize(&stack);
    char s;
    int x,i;
    printf("enter the number in decimal");
    scanf ("%d",&x);
    printf("enter to which base you need it changed\n 'b' for binary \n 'o' for octal\n 'h' for hexadecimal");
    scanf("%c",&s);
    switch(s)
    {
    case b :
        {
             for(i=0;x>0;i++)
             {
                 push(&stack,x%2);
                 n=n/2;
             }

        }
    case o:
        {
            for(i=0;x>0;i++)
            {
                push(&stack,x%8);
                x=x/8;
            }
        }
    case h:
        {
            for(i=0;x>0;i++)
            {
                temp=x%16
                if(temp<9)
                    push(&stack,temp);
                else if(temp>9&&<16)
                    push(&stack,'A'+temp%10);
            }
        }


    }
    puts(stack);

}

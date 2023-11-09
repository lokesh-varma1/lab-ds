#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *s) {
    strcpy(stack[++top], s);
}

char *pop() {
    return stack[top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefix_to_infix(char *prefix, char *infix) {
    int i, j;
    char op1[MAX], op2[MAX], tmp[MAX];

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (is_operator(prefix[i])) {
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(tmp, "(%s%c%s)", op1, prefix[i], op2);
            push(tmp);
        } else {
            sprintf(tmp, "%c", prefix[i]);
            push(tmp);
        }
    }

    strcpy(infix, pop());
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter a prefix equation: ");
    scanf("%s", prefix);

    prefix_to_infix(prefix, infix);

    printf("Infix equation: %s\n", infix);

    return 0;
}

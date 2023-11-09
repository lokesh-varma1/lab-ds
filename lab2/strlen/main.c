#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n,i;
    char str1[100];
    printf ("enter string:");
    scanf("%s",str1);
    i=0;
    while(str1[i]!='\0')
    {
        n++;
        i++;
    }
    printf("the length of the string is:%d",n);
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i,a,b;
    char *n;
    char temp[100],s[100],ss[100];
    printf("enter string:");
    gets(s);
    printf("enter substring:");
    gets(ss);
    *n=strstr(s,ss);
    a=strlen(ss);
    for(i=0;i<a;i++)
    {
         s[i+*n]='\0';
    }
    printf("the string after deletion:",s);
}

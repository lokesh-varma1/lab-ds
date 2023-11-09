#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i,n,a,b;
    char temp[100],s[100],ss[100];
    printf("enter string:");
    gets(s);
    printf("enter substring:");
    gets(ss);
    printf("which position to enter the substring:");
    scanf("%d",&n);
    a=strlen(s);
    b=strlen(ss);
    for(i=0;i<a-n+1;i++)
    {
         temp[i]=s[n-1+i];
         s[n-1+i]='\0';
    }
    strcat(s,ss);
    strcat(s,temp);

    printf("the string after insertion:%s",s);
}


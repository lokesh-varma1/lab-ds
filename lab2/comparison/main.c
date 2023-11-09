#include <stdio.h>
#include <stdlib.h>
int strlength(char a[100])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return(i+1);

}
void main()
{
    int n,i;
    char str2[100],str1[100];
    printf("enter the first string:");
    gets(str1);
    printf("enter string no 2:");
    gets(str2);
    if(strlength(str1)!=strlength(str2))
        printf("not the same");
    else
    {
    for(i=0;i<strlength(str1);i++)
    {
        if (str1[i]!=str2[i])
            n=1;
    }
    if(n==1)
        printf("not the same");
    else
        printf("they are the same");
    }

}


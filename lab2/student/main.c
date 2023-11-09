#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n,i,j;
    char str1[100],str2[100];
    printf ("enter string no 1:");
    scanf("%s",str1);
    printf("enter string no 2:");
    scanf("%s",str2);
    i=0;
    while(str1[i]!='\0')
    {
        n++;
        i++;
    }
    j=n;
    i=0;
    while(str2[i]!='\0')
    {
        str1[j]=str2[i];
        j++;
        i++;
    }
    str1[j]='\0';

    printf("the concatenated string is:%s",str1);


}


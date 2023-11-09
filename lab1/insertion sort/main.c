#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,key,n,a[100];
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the list of elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0&&key<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
        printf("the sorted list of elements=");
        for(i=0;i<n;i++)
            printf("%d",a[i]);
}

#include<stdio.h>//æÿ’Û≥À∑® 
int main()
{
    int a[100][100],b[100][100],n,m,p,q,i,j,k,sum;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
    scanf("%d%d",&p,&q);
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
        scanf("%d",&b[i][j]);
    if(m!=p) printf("sad");
    else
    {
        for(i=0;i<n;i++)
        {   
            for(j=0;j<q;j++)
            {
                sum=0;
                for(k=0;k<m;k++)sum+=a[i][k]*b[k][j];
                printf("%d ",sum);    
            }
        putchar('\n');
        }
    }
    return 0;
}


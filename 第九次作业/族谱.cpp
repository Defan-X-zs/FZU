#include<stdio.h>//×åÆ×
int id[200001]={0};
int main()
{
    int find(int x);
    int n,k,i,sum=0,a,b,a1,b1;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&id[i]);
        if(id[i]==0)sum++;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        if(sum==1)
        {
            printf("Yes\n");
            continue;
        }
        a1=find(a);
        b1=find(b);
        if(a1==b1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
int find(int x)
{
    int y;
    if(id[x])
    {
        y=find(id[x]);
        id[x]=y;
    }
    if(!id[x])return x;
}

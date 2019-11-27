#include <iostream>//8.1 批作业调度问题
#include <algorithm>
using namespace std;
struct node
{
    int c1,c2;
    bool operator<(const node&x) const
    {
        if (c1==x.c1)
        {
            return c2>x.c2;
        }
        else return c1<x.c1;
    }
}que[2001];
int array[50001];
int main()
{
    int n,i;
    int x,y;
    int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&que[i].c1,&que[i].c2);
    sort(que,que+n);
    for(i=n-1;i>=0;i--)
    {
        x=que[i].c1;
        y=que[i].c2;
        while(y)
        {
            x++;
            if(array[x]==0)
            {
                array[x]=1;
                y--;
            }
        }
        ans+=x;
    }
    printf("%d\n",ans);
    return 0;    
}

#include<iostream>//7-1 堆中的路径
using namespace std;
int  h[1005]; //用数组来存放堆
int size=0;
void  swap(int x, int  y)
{
    int  t;
    t=h[x];
    h[x] = h[y];
    h[y] = t;
}
void  siftdown(int  i, int n)
{
    int t,flag=0;
    while(i*2 <=n && flag ==0 )
    {
        if(h[i] > h[i*2])
            t=i*2;
        else
            t=i;
        if(i*2+1 <=n )  
        {
            if(h[t]>h[i*2+1] )
                t= i*2+1;
        }
        if(t!=i)
        {
            swap(t,i);
            i=t;
        }
        else
            flag =1;
    }
}
void Insert(int x)
{
    size++;
    int i;
    for(i=size;h[i/2]>x;i/=2) 
    {
        h[i]=h[i/2];
    }
    h[i]=x; 
}
int main ()
{
    int n,m;
    cin>>n>>m;
    h[0]=-10005;
    for(int i=1; i<=n; i++)
    {
    	int k;
    	cin>>k;
        Insert(k);
    }
    int t;
    for(int i = 1; i<=m; i++)
    {
        cin>>t;
        cout<<h[t];
        for(;t/2>0;t/=2)
        {
            cout<<' '<<h[t/2];
        }
        cout<<endl;
    }
}

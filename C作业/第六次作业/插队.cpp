#include<stdio.h>//²å¶Ó
int main()
{
	int a[1001][2],n,i,x,k,l;
scanf("%d",&n);
for(i=n;i>0;i--)
{
	scanf("%d",&a[i][1]);
	a[n-i+1][2]=i;
}a[0][1]=10000;
for(l=1;l<n;l++)
{
	for(i=n,k=1;k<=n;k++,i--)
	{
		if(a[i-1][1]<a[i][1])
		{
	    x=a[i-1][1],a[i-1][1]=a[i][1],a[i][1]=x;
	    x=a[i-1][2],a[i-1][2]=a[i][2],a[i][2]=x;
		} 
	    if((a[i-1][1]==a[i][1])&&(a[i-1][2]>a[i][2]))
		{
    	x=a[i-1][2],a[i-1][2]=a[i][2],a[i][2]=x;
		}
	}
}
for(i=1;i<n;i++)printf("%d %d\n",a[i][1],a[i][2]);printf("%d %d\n",a[n][1],a[n][2]);
return 0;
}

#include<stdio.h>
#include<math.h>
int zhi(int m)
{
	int j;
	if(m==1)return 0;
	else 
	{
	for(j=2;j<=sqrt(m);j++)
	{
		if(m%j==0)break;
		
	}
	if(j<=sqrt(m))return 0;
		else return 1;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,a[1000],i;
	int l,r,num=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(l=0;l<n;l++)
	{
		if(!zhi(a[l]))continue;
		for(r=l;r<n;r++)
		{
			if(!zhi(a[r]))continue;
			if(zhi(r-l+1))
			num+=1;
		}
	}
	printf("%d",num);
return 0;
}

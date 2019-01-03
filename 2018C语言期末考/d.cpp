#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,a[100][100],b[100],c[100];
	int i,j,f,bmax=-1,cmax=-1,bmaxn,cmaxn;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		scanf("%d",&a[i][j]);
	}
	
	for(i=0;i<n;i++)
	{
		b[i]=0;
		for(j=0;j<m;j++)
		{
			b[i]+=a[i][j];
		}
		if(b[i]>bmax){bmax=b[i];bmaxn=i;}
	}
	
	for(j=0;j<m;j++)
	{
		c[j]=0;
		for(i=0;i<n;i++)
		{
			c[j]+=a[i][j];
		}
		if(c[j]>cmax){cmax=c[j];cmaxn=j;}
	}
	if(bmax>cmax) printf("0 %d",bmaxn+1);
	else if(bmax<cmax) printf("1 %d",cmaxn+1);
	else printf("0 %d",bmaxn+1);
	
		

return 0;
}

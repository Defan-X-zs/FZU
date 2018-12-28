#include<stdio.h>//Elitist Linear Algebra Class
int main()
{
	int n,m,max,i,j,f,t,a[100][100],b[100];
	scanf("%d%d",&n,&m);//row n,colume m;
	for(i=0;i<n;i++)
	{	
		max=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]>max)
			{max=a[i][j];b[i]=j;}
		}
	}
	for(i=0;i<n;i++)
	{
		f=1;t=b[i];
		for(j=0;j<n;j++)
		{
			if(a[i][t]>a[j][t])
			{	
				f=0;
				break;
			}
		}
		if(f)
		{
			printf("%d %d",i+1,b[i]+1);
			break;
		}
	}
return 0;
} 

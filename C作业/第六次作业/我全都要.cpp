#include<stdio.h>//我全都要 
int main()
{	
	int a[10000],sum,maxsum=-500;
	unsigned int j,i,n;
    scanf("%d",&n); 
    for(i=0;i<n;i++)scanf("%d",&a[i]); 
	for(i=0;i<n;i++) 
	{			
		sum=0;			
		for(j=i;j<n;j++) 
		{				
			sum+=a[j];				
			if(sum>maxsum) 
			{maxsum=sum;}			
		}		
	}
	printf("%d",maxsum);
return 0;
}

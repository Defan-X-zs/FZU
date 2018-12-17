#include<stdio.h>//É¾³ýÔªËØ
int main()
{
int m,n,i,j,k,a[1000],b,flag=0;
scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]); 
	}
scanf("%d",&m);
for(i=0;i<m;i++)
{
	scanf("%d",&b);
	for(j=n;j>0;j--)
	{
		if(a[n]==b){flag++;break;}
		if(a[j]==b)
		{
			k=j;
			while(k+1<=n){a[k]=a[k+1];k++;}
			flag++;
			break;
		}
	}
}
for(i=0;i<n-flag-1;i++){printf("%d",a[i]);putchar(' ');}
printf("%d\n",a[n-flag-1]);
return 0;
}

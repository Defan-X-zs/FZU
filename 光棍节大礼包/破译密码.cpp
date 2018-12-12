#include<stdio.h>//ÆÆÒëÃÜÂë 
int main()
{
	int a1,a2,a3,a4,i1,i2,i3,i4,f=0;
	scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
	for(i1=-100;i1<=100;i1+=1)
	{
		for(i2=-100;i2<=100;i2+=1)
		{
			for(i3=-100;i3<=100;i3+=1)
			{
				if(a1*i1+a2*i2+a3*i3==0)f++;
				for(i4=-100;i4<0;i4+=1)
				{
					if(a1*i1+a2*i2+a3*i3+a4*i4==0)f+=2;
				}
			}
		}
	}
	printf("%d",f);
	return 0;
}


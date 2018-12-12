#include<stdio.h>//snooker
int main()
{
	int ball,s1,s2,r,i;
	scanf("%d%d%d",&ball,&s1,&s2);
	if(ball<=6)
	{
		for(i=ball;i>0;i--)
		{
			s1+=i+1;
		}
		if(s1>s2)printf("YES");
		else printf("NO");
	}
	else
	{
		r=ball-6;
		s1=1+r+7*(r-1)+27;
		if(s1>s2)printf("YES");
		else printf("NO");
	}
	return 0;
}


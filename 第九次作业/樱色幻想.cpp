#include<stdio.h>//樱色幻想 
int main()
{
	int i=1,n,m;
	int j,k,l;
	int diam(int n,int m);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("Case #%d:\n",i++);
		if(n==1)
		{
			for(l=1;l<=m;l++)//行 
			{
				for(j=1;j<=m-l;j++)
				{
					putchar(' ');
				}
				for(j=1;j<=2*l-1;j++)
				{
					putchar('*');
				}
				putchar('\n');
			}
            for(l=1;l<m;l++)
            {
                for(j=1;j<=l;j++)
                {
                    putchar(' ');
                }
                for(j=1;j<=2*(m-l)-1;j++)
                {
                    putchar('*');
                }
                putchar('\n');
            }
		}
        if(n==0)
		{
			for(l=1;l<=m;l++)//行 
			{
				for(j=1;j<=m-l;j++)
				{
					putchar(' ');
				}
                    if(l!=1)putchar('*');
				for(j=1;j<=2*l-3;j++)
				{
					putchar(' ');
				}
                      putchar('*');
				putchar('\n');
			}
            for(l=1;l<m;l++)
            {
                for(j=1;j<=l;j++)
                {
                    putchar(' ');
                }
                if(l!=m-1)putchar('*');
                for(j=1;j<=2*(m-l)-3;j++)
                {
                    putchar(' ');
                }
                putchar('*');
                putchar('\n');
            }
		}
	}
	return 0;
}

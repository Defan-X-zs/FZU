/*判断素数*/
for(j=2;j<=sqrt(m);j++)
  {
  if(m%j==0)break;
  }  
  if(j<=k)printf("NO\n");
  else printf("YES\n");
/*输入区间*/  
for(;i<=n;i++)
	{
	scanf("%d",&a[i]);
	a[i]+=a[i-1];
    }
    
while(scanf("%d%d",&n,&m)!=EOF)
/*正*金字塔*/ 
for(l=1;l<=m;l++)
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
/*倒*金字塔*/ 
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
/*空金字塔*/ 
for(l=1;l<=m;l++)
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
/*冒泡大到小*/ 
for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]<a[i+1])
			{
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
			}
		}
	}
//printf("%o",a);
/*legal date*/
if(m<13)
{
	if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d<32)
	printf("Yes");
	else if((m==4||m==6||m==9||m==11)&&d<31) printf("Yes");
	else if((m==2)&&(y%4==0)&&(y%100!=0||y%400==0)&&d<30) printf("Yes");
	else if(d<29)printf("Yes");
	else printf("No");
}
/*进制转换*/
while(n>0)
{
a[i]=n%2; 
i=i+1;
n=n/2;
}
for(;i>0;i--)
printf("%d",a[i-1]);	 

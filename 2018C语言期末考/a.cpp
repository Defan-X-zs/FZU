#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long n,min=2147483647,a;
	scanf("%lld",&n);
	for(;n>0;n--)
	{
		scanf("%lld",&a);
		if(a<min) min=a;
	}
	printf("%lld",min);

return 0;
}

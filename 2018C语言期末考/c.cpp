#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,x,y,z,x1,y1,z1;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(;n>0;n--){
		scanf("%d%d%d",&x1,&y1,&z1);
		x+=x1;y+=y1;z+=z1;
	}
	printf("%d %d %d",x,y,z);

return 0;
}

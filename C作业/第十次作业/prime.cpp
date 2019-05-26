#include<stdio.h>//ËØÊı prime
#include<math.h>
int main()
{
  int n,m,i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  scanf("%d",&m);
  k=sqrt(m);
  for(j=2;j<=k;j++)
  {
  if(m%j==0)break;
  }
  if(j<=k)printf("NO\n");
  else printf("YES\n");
 }
 return 0;
}

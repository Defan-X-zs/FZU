#include<stdio.h>//7-11 利用指针返回多个函数值
int max_min(int a[],int len,int* pmax,int* pmin);
int main() 
{
  	int n,i,max,min,len=0;
  	int *pmax,*pmin;
  	int a[10000];
  	scanf("%d",&n);
  	for(i=0;i<n;i++) {
  	  	scanf("%d",&a[i]);
  	  	len++;
  	}
  	max_min(a,len,&max,&min);
  	printf("max = %d\nmin = %d",max,min);
  	return 0;
}
int max_min(int a[],int len,int* pmax,int* pmin){
  	int i;
  	*pmax=a[0];
  	*pmin=a[0];
  	for(i=1;i<len;i++){
		if(*pmax<a[i]) *pmax=a[i];
		if(*pmin>a[i]) *pmin=a[i];
    }
}


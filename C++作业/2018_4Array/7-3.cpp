#include<iostream>//7-3 查验身份证 err
#include<string>
using namespace std;
int main()
{
	int n,i,f = 1,sum[100]={0},mod,m[100]={0};
	string a[100];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i][17]=='X')
			a[i][17]=58;
	}
	for(i=0;i<n;i++)
	{
		sum[i]=(a[i][0]-48)*7+(a[i][1]-48)*9+(a[i][2]-48)*10+(a[i][3]-48)*5+(a[i][4]-48)*8+(a[i][5]-48)*4+(a[i][6]-48)*2+(a[i][7]-48)*1+(a[i][8]-48)*6+(a[i][9]-48)*3+(a[i][10]-48)*7+(a[i][11]-48)*9+(a[i][12]-48)*10+(a[i][13]-48)*5+(a[i][14]-48)*8+(a[i][15]-48)*4+(a[i][16]-48)*2;
		mod=sum[i]%11;
		if(mod>1&&mod<11)
			m[i]=12-mod;
		else if(mod==0)
			m[i]=1;
		else if(mod==1)
			m[i]=0;
		if(a[i][17]-48!=m[i])
		{
			if(a[i][17]==58)
				a[i][17]='X';
			cout<<a[i]<<endl;
			f = 0;
		}
	}
	if(f) cout<<"All passed"<<endl;
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	char num[18];
	int sum;
	char C;
	int a[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char z[11] = { '1' ,'0' ,'X', '9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2' };
	int N;

 while(scanf("%d",&N)!=EOF) 
 {
    int t =N;
	int cnt = 0;
	while(t--)
	{	
		sum=0;
	 	scanf("%s",&num);
	 	int flag=0;
	 	for(int i=0;i<=16;i++)
	 	   if(!(num[i]>='0'&&num[i]<='9'))
			{ 
	 	      flag=1;
	 	      break;
	 	    }
	 	 
	  if(flag==0)
	{ 
		for(int i=0;i<=16;i++)
		   for( int j=0;j<=10;j++)
		      if(num[i]=='0'+j)
			  {
		      	sum=sum+j*a[i];
		      	break;
			  }
	    sum=sum%11;
		if(z[sum]==num[17]) 
		     cnt++;
		else{
			for(int i=0;i<=16;i++)
			  printf("%c",num[i]);
			  printf("%c\n",num[17]);
	        }
	  if( cnt==N )
	    printf("All passed\n");
	}
	 else if(flag== 1){
	 	for(int i=0;i<=16;i++)
			  printf("%c",num[i]);
			  printf("%c\n",num[17]);
	   		}
	}
}
	return 0;
}


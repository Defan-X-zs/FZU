#include<iostream>//世界杯
using namespace std;
class team
{
private:
	int name;
	int num[20][2];
	int sum;
public:
	int n;
	team(int name,int nu[20][2],int n):name(name),n(n){for(int i=0;i<n;i++){num[i][0]=nu[i][0];num[i][1]=nu[i][1];}}
	int summeasure()
	{	int ssum=0;
		for(int i=0;i<n;i++)
		{
			if(num[i][0]<num[i][1])
			{
				if(name==1){ssum+=0;}
				else ssum+=3;
			}
			else if(num[i][0]>num[i][1])
			{
				if(name==1){ssum+=3;}
				else ssum+=0;
			}
			else ssum+=1;
		}
		return ssum;
	}
	int winsum()
	{
		int win=0;
		for(int i=0;i<n;i++)
		{
			if(num[i][0]!=num[i][1])
			{
				if(name==1){win+=num[i][0]-num[i][1];}
				else win-=num[i][0]-num[i][1];
			}
			else win+=0;
		}
		return win;
	}
};
int main()
{
	int name;
	cin>>name;
	int a,b;char c;int n=0;int num[20][2];
	cin>>num[n][0];
	getchar();
	cin>>num[n][1];n++; 
	while(1)
	{
		cin>>num[n][0];
		getchar();
		cin>>num[n][1];n++; 
		c=getchar();
		if(c=='\n')break;
	}
	team f(name,num,n);
	cout<<f.summeasure()<<" "<<f.winsum();
}

//2.7 大家一起来报数Ⅱ
#include<iostream>
using namespace std;
int main()
{
	int T;//次数
	cin>>T;
	for(int i = 0; i < T; i++)
	{ 
		int	n, m;//n个人报到m停止
		cin>>n>>m; //cout<<n<<' '<<m<<' ';
		int a[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = i + 1;//cout<<'a';
		}
		int count = 1;//报的数
		int quitsum = 0;//退出的人数
		int t = 0;//当前指针
		int tp=n-1, tn=1;
		while(quitsum < n - 2)
		{
			if(m!=1)t++;
			if((a[t] != 0)&&m!=1) {count++;/*cout<<cout<<' ';*/}
			if(count == m)
			{	//cout<<t<<endl;
				tp = t-1;//cout<<tp;
				tn = t+1;//cout<<tn<<endl;
				while(a[tp]==0)
				{
					tp--;
					if(tp<0) tp+=n;
				}
				while(a[tn]==0)
				{   
					tn++;
					if(tn>n-1) tn-=n;
				}
				a[tp] = 0;//cout<<tp;
				a[tn] = 0;//cout<<tn<<endl;
				count = 1;
				t+=2;
				quitsum+=2;
			}
			if(t>n-1) t-=n;
		}
		int res[2], r=0;
		for(int i = 0; i < n; i++)
		{
			if(a[i]!=0&&(n-quitsum)==1)
			{
				res[r]=a[i];
				break;
			}
			if(a[i]!=0&&(n-quitsum)==2)
			{
				res[r++] = a[i];
			}
		}
		if(n-quitsum==1) cout<<res[0]<<endl;
		else if(res[0]>res[1]) cout<<res[1]<<' '<<res[0]<<endl;
		else cout<<res[0]<<' '<<res[1]<<endl;
	}
}
/*报到 m 时停止，在报到 m 的那个人的左右的两个人出列，
从他在顺时针方向下一个人开始重新从 1 报数，如此下去。
如果还在游戏的人数少于 3 个，则游戏终止。
在一行内输出最后留下来的人编号*/

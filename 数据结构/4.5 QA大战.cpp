#include<iostream>//4.5 QA大战
#include<queue>
using namespace std;
int main()
{
	queue<int>s;
	string c;
	int a, b, head, t, n = 1;
	int flag[2001]={0};
	cin>>c;
	while(c=="PUSH")//当输入为END时结束
	{
		cin>>a>>b;
		if(n){head = a, n=0;}//保存列表头
		if(flag[b])//之前出现过 即flag不为零
		{
			while(s.front() != flag[b])//向后循环队列 到达需要插入的点
			{
				t = s.front();//读取列表头的值
				s.pop();
				s.push(t);//将头的值放入列表尾 完成一次移位
			}
			t = s.front();
			s.pop();
			s.push(t);
			s.push(a);//插入a值
			while(s.front() != head)//插入后需恢复到列表没有移位前的状态
			{
				t = s.front();
				s.pop();
				s.push(t);
			}
			flag[b]=a;//更新flag值
		}
		else//之前没出现过 即flag为零
		{
			flag[b] = a;//更新flag的值 为应该插入的位置
			s.push(a);//插入至列表尾
		}
		cin>>c;
	}
	while(!s.empty())//输出列表
	{
		cout<<s.front();
		s.pop();
		if(!s.empty())cout<<" ";//保证最后一位数字后没空格
	}
}

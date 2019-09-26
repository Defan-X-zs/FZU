#include<iostream>//3.1 括号
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	stack<char> s;//建立栈
	char a[1000000];
	cin>>a;//输入括号串
	int flag[strlen(a)];//建立标志数组
	for(int i = 0; i < strlen(a); i++)
	{
		if(a[i]=='(')
		{
			s.push(i);//碰到左括号 将该括号的位置i入栈
		}
		else if(a[i]==')'&&!s.empty())//碰到右括号且栈不为空
		{
			int left = s.top();//括号匹配成功 读取左括号的位置
			s.pop();//将配对成功的左括号的位置弹出栈
			flag[i] = 1;//配对成功的右括号的位置在flag中标为1
			flag[left] = 1;//配对成功的左括号的位置在flag中标为1
		}
	}
	int maxlen=0,maxtime=0,templ=0;
	for(int i = 0; i < strlen(a); i++)
	{
		if(flag[i]==1)
		{
			templ++;//开始计算有效长度
		}
		else{templ=0;}
		if(templ>maxlen)
		{
			maxlen=templ;//将临时的长度存入maxlen
			maxtime=1;//将该长度括号出现的次数初始化为1
		}
		else if(templ==maxlen) maxtime++;//遇到临时长度与maxlen相同时 该长度括号出现的次数maxtime加1
	}
	if(maxlen==0) cout<<"0"<<endl<<"1";//输出结果
	else cout<<maxlen<<endl<<maxtime; 
}

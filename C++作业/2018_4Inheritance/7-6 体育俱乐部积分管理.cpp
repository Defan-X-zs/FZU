//7-6 体育俱乐部积分管理
#include <iostream>
using namespace std;
class Ball{
protected:
	string opponent;
	int a, b;
public:
	Ball(string o, int a1, int b1):opponent(o),a(a1),b(b1){}
	void display();
};
class Basketball:public Ball{
public:
	Basketball(string o, int a, int b):Ball(o, a, b){}
	void display(){
		if(a>b) cout<<opponent<<" 2"<<endl;
		else if(a<b) cout<<opponent<<" 1"<<endl;
		else cout<<opponent<<" 0"<<endl;
	}
};
class Football:public Ball{
public:
	Football(string o, int a, int b):Ball(o, a, b){}
	void display(){
		if(a>b) cout<<opponent<<" 3"<<endl;
		else if(a<b) cout<<opponent<<" 0"<<endl;
		else cout<<opponent<<" 1"<<endl;
	}
};
class Volleyball:public Ball{
public:
	Volleyball(string o, int a, int b):Ball(o, a, b){}
	void display(){
		if(a-b>=2) cout<<opponent<<" 3"<<endl;
		else if(a-b==1) cout<<opponent<<" 2"<<endl;
		else if(a-b==-1) cout<<opponent<<" 1"<<endl;
		else cout<<opponent<<" 0"<<endl;
	}
};
int main(){
	Ball *pb[20];
	int func, a, b;
	string o;
	char c;
	cin>>func;
	while(func){
		switch(func){
			case 1:{cin>>o>>a>>c>>b;Basketball t(o, a, b);t.display();break;}
			case 2:{cin>>o>>a>>c>>b;Football t(o, a, b);t.display();break;}
			case 3:{cin>>o>>a>>c>>b;Volleyball t(o, a, b);t.display();break;}
		}
		cin>>func;
	}
}
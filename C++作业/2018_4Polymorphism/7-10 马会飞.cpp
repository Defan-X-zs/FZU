//7-10 马会飞
#include <iostream>
using namespace std;
class Horse
{
public:
	Horse(){cout<<"Horse 申请了空间..."<<endl;}
	virtual ~Horse(){cout<<"Horse 释放了空间..."<<endl;}
	virtual void Fly(){cout<<"Just a horse."<<endl;}
};  
class Pegasus:public Horse
{
public:
	Pegasus(){cout<<"Pegasus 申请了空间..."<<endl;}
	~Pegasus(){cout<<"Pegasus 释放了空间..."<<endl;}
	void Fly(){cout<<"I can fly!"<<endl;}
};
int main()
{
	Horse *p1 = new Horse; 
	//输出：Horse 申请了空间...
	Horse *p2 = new Pegasus; /*  输出两行：
	                Horse 申请了空间...
	              Pegasus 申请了空间...   
			         */	
	cout << endl; 
	p1->Fly(); //输出：Just a horse.
	p2->Fly(); //输出：I can fly!
	cout << endl; 
	delete p1; //输出：Horse 释放了空间...
	delete p2;  /* 输出两行：
	               Pegasus 释放了空间... 
	               Horse 释放了空间... 
		    */
	return 0;
}

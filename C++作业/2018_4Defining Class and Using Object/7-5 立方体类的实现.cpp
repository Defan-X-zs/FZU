//7-5 立方体类的实现
#include<iostream>
using namespace std;
class Box{
private:
	int a;
public:
	void seta(int l){
		a=l;
	}
	void getvolume(){
		cout<<a*a*a<<" ";
	}
	void getarea(){
		cout<<a*a*6;
	}
	void disp(){
	}
};
int  main( ){
    float ab;
    cin>>ab;
    Box  obj;
    obj.seta( ab );
    obj.getvolume( );
    obj.getarea( );
    obj.disp( );
    return 0;
}


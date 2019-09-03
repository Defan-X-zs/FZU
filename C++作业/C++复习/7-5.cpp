#include<iostream>//复数求模模板
#include<math.h>
using namespace std;
template <class T>
class complex
{
private:
	T a,b;
public:
	complex(T a,T b):a(a),b(b){}
	T sum()
	{
		return sqrt(a*a+b*b);
	}
};
int main()
{
	int t;
	int a,b;
	float c,d;
	double e,f;
	cin>>t;
	if(t==1){cin>>a>>b;complex <int> n(a,b);cout<<n.sum()<<endl;}
	else if(f==2){cin>>c>>d;complex <float> n(c,d);cout<<n.sum()<<endl;}
	else{cin>>e>>f;complex <double> n(e,f);cout<<n.sum()<<endl;}
	
}
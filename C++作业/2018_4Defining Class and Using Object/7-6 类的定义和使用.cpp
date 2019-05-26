// 7-6 类的定义和使用
#include<iostream>
using namespace std;
class DDate{
private:
    int year,month,day;
public:
    DDate(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    void isLeap(DDate );
};
void DDate::isLeap(DDate a)
{
    if((a.year%100!=0&&a.year%4==0)||(a.year%400 == 0))
    cout<<"yes";
    else cout<<"no";
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    DDate x(a,b,c);
    x.isLeap(x);
}


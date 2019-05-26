//7-1 类的定义和使用
#include<iostream>
using namespace std;
class Point{
private:
    int x,y;
public:
Point(int a,int b)
{
    x=a;
    y=b;
}
void move(int m,int n)
{
    x=x+m;
    y=y+n;
    cout<<x<<" "<<y;
}
};
int main()
{
    int a,b,c,d;
    cin>>a>>b;
    Point p(a,b);
    cin>>c>>d;
    p.move(c,d);

}

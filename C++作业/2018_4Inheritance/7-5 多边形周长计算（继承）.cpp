//7-5 多边形周长计算（继承）
#include<iostream>
using namespace std;
class polygon{
protected:
    int number;
private:
    int side_length[100];
public:
    polygon(){};
    polygon(int n):number(n){};
    polygon(int n,int x[]); 
    int perimeter();
    void display();
}; 
class rectangle : public polygon{
private:
    int height;
    int width;
public:
    rectangle(){};
    rectangle(int a,int b):height(a),width(b){}; 
    int perimeter();
    void display1();
};
class equal_polygon : public polygon{
private:
    int side_len;
public:
    equal_polygon();
    equal_polygon(int n, int x):polygon(n){side_len = x;}; 
    void display2();
    int perimeter(){return number * side_len;}
}; 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        switch(type)
        {
        case 0:
            {
                int n=0,lenth;
                int x[100];
                while(cin>>lenth)
                {    
                    if(lenth==-1)break;
                    x[n++]=lenth;
                }
                polygon h0(n, x);
                h0.display();
            }
            break;
        case 1:
            {
                int h,w;
                cin>>h>>w;
                rectangle h1(h, w);
                h1.display1();
            }
            break;
        case 2: 
            {
                int n,x;
                cin>>n>>x;
                equal_polygon h2( n, x );
                h2.display2();
            }
            break;
        }
    }
    return 0;
}
void equal_polygon::display2()
{
    cout<<number<<" "<<perimeter()<<endl;    
}
void rectangle::display1()
{
    cout<<"4 "<<2*(height + width)<<endl;
}
int polygon::perimeter()
{
    int sum=0;
    for(int i=0;i<number;i++)
    {
        sum += side_length[i];
    }
    return sum;
}
void polygon::display()
{
    cout<<number<<" "<<perimeter()<<endl;
}
polygon::polygon(int n, int x[])
{
    number = n;
    for(int i=0;i<n;i++)
    {
        side_length[i] = x[i];
    }
}
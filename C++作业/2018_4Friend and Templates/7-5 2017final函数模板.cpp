#include<iostream>//7-5 2017finalº¯ÊıÄ£°å
#include<math.h>
using namespace std;
class point
{
      float x;
      float y;
      float z;
      public:
             double operator - (point&);
             friend istream& operator >>(istream&,point&);
};
double point::operator - (point& p)
{
       return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
}
istream& operator >>(istream& in,point& p)
{
        in>>p.x>>p.y>>p.z;
        return in;
}
template<class T>
double dist(T a,T b)
{
       return fabs(a-b);
}
int main()
{
    int i1,i2,act;
    float f1,f2;
    point p1,p2;
    cin>>act;
    while(act)
    {	
              switch(act)
              {
                         case 1:cin>>i1>>i2;cout<<dist(i1,i2);break;
                         case 2:cin>>f1>>f2;cout<<dist(f1,f2);break;
                         case 3:cin>>p1>>p2;cout<<dist(p1,p2);break;
              }
              cout<<endl;
              cin>>act;
    }
    return 0;
}

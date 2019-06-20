//7-3 点到原点的距离（多态）
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
protected:
    int dimension;//点的维数，最多不超过100维
private:
    float point_length[100];//点数组
public:
    Point (){};//构造函数根据需要重载
    Point (int a, float b[]) : dimension(a){
        //这里实现传指针赋值给数组
        for(int i=0;i<a;i++)
        {
            point_length[i] = b[i];
        }
    };
    virtual float distance( ){
        float ans=0;
        for(int i=0;i<dimension;i++)
        {
            ans += (point_length[i] * point_length[i]);
        }
        return sqrt(ans);
    };
    virtual void display( ){
    //Distance from Point(1,1,1,1,1) to original point is 2.23607
    if(dimension == 1 ){
        cout<<"Distance from Point"<<point_length[0]<<" to original point is " << fabs(point_length[0]) <<endl;
    }
    else{
        cout<<"Distance from Point(";
        for(int i=0;i<dimension-1;i++)
        {
            cout<<point_length[i]<<",";
        }
        cout<<point_length[dimension-1]<<") to original point is "<<distance()<<endl;
        };        
    }

};
//二维点 
class Point_2D : public Point{
protected:
    float x;//2D平面上点的x坐标
    float y;//2D平面上点的y坐标
public:    
    Point_2D( ) { };//无参和参数化构造函数
    Point_2D(float a,float b) : Point( ) , x(a) , y(b){ dimension = 2; };
    float distance( ) { return sqrt(x*x + y*y); };//计算当前点到原点的距离
    void display( ) { 
    //Distance from Point(3,4) to original point is 5
        cout<<"Distance from Point("<<x<<","<<y<<") to original point is "<<distance()<<endl;
    };//输出点
}; 
//以Point为基类建一个派生类Point_3D，增加以下数据成员：
//三维点 

class Point_3D : public Point{
protected:
    float x;//3D平面上点的x坐标
    float y;//3D平面上点的y坐标
    float z;//3D平面上点的z坐标
public:/**/
    Point_3D( ){ };//无参和参数化构造函数
    Point_3D(float a,float b,float c) : Point( ) , x(a) , y(b) , z(c) { dimension = 3; };
    float distance( ) { return sqrt( x*x + y*y + z*z ); };//计算当前点到原点的距离
    void display( ){
    //Distance from Point(1,2,2) to original point is 3
    cout<<"Distance from Point("<<x<<","<<y<<","<<z<<") to original point is "<<distance()<<endl;
    } ;//输出点
};
//****注意！派生类的成员成员函数要有定义，不然编译不过“returned 1” 


int main()
{
    int type,count=0;
    Point *pt [10];
    
    while(cin>>type){
        if(type == 0)break;                                            
        switch(type){
        case 1:{
            int len;
            float hello[100];
            cin>>len;
            for(int i=0;i<len;i++){
                cin>>hello[i];
            } 
            pt[count++] = new Point(len,hello);             
            break;
        }
        case 2:{
            float a,b;
            cin>>a>>b;
            pt[count++] = new Point_2D(a,b);            
            break;
        }
        case 3:{
            float a,b,c;
            cin>>a>>b>>c;
            pt[count++] = new Point_3D(a,b,c);
            break;
        }
        }
    }
    for(int i=0;i<count;i++) 
    {
        pt[i]->display();
    }
    return 0;
}
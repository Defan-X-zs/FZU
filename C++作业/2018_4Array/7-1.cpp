#include <iostream>//7-1 说反话-加强版
#include <stack>  
#include <string>  
using namespace std;  
int main()  
{  
    stack<string> s;//定义一个栈 
    string  sp;  
    bool flag=false;  
    while(cin>>sp)//省略空格 
        s.push(sp);//压入栈   
    while(!s.empty())//如果栈不是空 
    {  
        if(flag)
            cout<<" ";//第一次不输出空格 
        else 
            flag=true;
        cout<<s.top(); 
        s.pop();//移除栈顶元素' '       
    }  
    return 0;  
}

#include <iostream>//7-1 科学计数法的值
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        string ans;//底数 
        bool flag,isSign,isMinus;
        int i;
        
        int len=str.size(); 
        string::size_type loc=str.find("^");//查找^ 
        //找不到返回-1，不为0为True。0为False 
        //任何存储string的size操作结果的变量必须为string::size_type类型。
        
        //检查指数+-
        if(str[loc+1]!='-') 
            isSign=false;
        else 
            isSign=true;
            
        if(!isSign)//指数部分为正 
        {
            int intcnt=0;//底数整数部分长度 
            for(i=0;str[i]!='*' && str[i]!='.';i++)
            {
                ans+=str[i];
                intcnt++;
            }
            
            if(str[i]=='.')     i++;//跳过小数点 
                
            int cnt=0;//底数小数部分长度 
            for(;str[i]!='*';i++)
            {
                ans+=str[i];
                cnt++;
            }

            int record;//指数数值 
            string tmp;//中间 
            stringstream ss;//流 
            
            if(loc==string::npos) 
                record = 1;
            else
            {
                for(i=loc+1;i<len;i++)//记录指数部分 
                    tmp+=str[i];

                ss<<tmp;//String
                ss>>record;//int
            }
            //判断是否不存在小数点 
            if(record<cnt)    
                flag = false;
            else    
                flag=true;
            
            int len1=ans.size();//底数部分长度 
            if(flag)//纯整数 
            {
                cout<<"The actual value for "<<str<<" is "<<ans;
                for (i=record-cnt;i>0;i--)    
                    cout<<"0";                    
                cout<<endl;
            }
            else//有小数点 
            {
                cout<<"The actual value for "<<str<< " is ";
                for (i=0;i<intcnt+record;i++)    
                    cout<<ans[i];    
                cout << ".";
                for (i=intcnt+record;i<len1;i++)    
                    cout<<ans[i];
                cout<<endl;
            }
        }
        else//指数部分为负
        {
            if(str[0]=='-')
            {
                str.erase(0,1);
                isMinus = true;
            }
            else
            {
                isMinus = false;
            }
            
            len=str.size();
            int intcnt=0;
            for(i=0;str[i]!='*' && str[i]!='.'; i++)
            {
                ans += str[i];
                intcnt++;
            }
            if(str[i]=='.')
                i++;
            for(;str[i]!='*';i++)
                ans += str[i];
            
            int record;
            string tmp;
            stringstream ss;
            if(loc==string::npos)
                record=1;
            else
            {
                if(isMinus)
                    for(i=loc+1;i<len;i++)    
                        tmp+=str[i];
                else
                    for(i=loc+2;i<len;i++)    tmp+=str[i];
                ss<<tmp;
                ss>>record;
            }
            cout<<"The actual value for "<<str<<" is ";
            if(isMinus)
                cout<<"-";
            cout<<"0.";
            
            for(i=0;i<record-intcnt;i++)    
                cout<<"0";
            cout<<ans<<endl;
        }
    }
    return 0;
}

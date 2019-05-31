//7-1 集合的模拟实现（类模板）
#include <iostream>
#include <string>
using namespace std;
template<class unmtype>
class MySet
{
    unmtype data[100];
    int i;
    public:
        MySet()
        {
            i=0;
        }
        void add(unmtype n);
        void deleted(unmtype n);
        void find(unmtype n);
};
template<class unmtype>
void MySet<unmtype>::add(unmtype n)
{
    int j;
    if(i==99)  cout<<"Full Set."<<endl;
    else
    {
        if(i==0)    
        {
            cout<<"0"<<endl;
            data[i]=n;
            i++;
        }
        else
        {
            for(j=0;j<i;j++)
            {
                if(data[j]==n)
                {
                   cout<<n<<" is already exist!"<<endl;
                   break;
                }
            }
            if(j==i)
            {
               cout<<j<<endl;
               data[j]=n;
               i++;
            }
        }
    }
}
template<class unmtype>
void MySet<unmtype>::deleted(unmtype n)
{
    int j,k;
    if(i==0)
    {
        cout<<n<<" is not exist!"<<endl;
    }
    else
    {
        for(j=0;j<i;j++)
        {
            if(data[j]==n)  break;
        }
        if(j==i)  cout<<n<<" is not exist!"<<endl;
        else
        {
            for(k=j;k<i-1;k++)
            {
                data[k]=data[k+1];
            }
            cout<<j<<endl;
            i--;
        }
    }
}
template<class unmtype>
void MySet<unmtype>::find(unmtype n)
{
    int j;
    if(i==0)   cout<<n<<" is not exist!"<<endl;
    else
    {
        for(j=0;j<i;j++)
        {
            if(data[j]==n)
            {
                cout<<j<<endl;
                break;
            }
        }
        if(j==i)   cout<<n<<" is not exist!"<<endl;
    }
}
int main()
{
    int flag,b;
    MySet<int>a;
    MySet<float>a2;
    MySet<string>a3;
    cin>>flag;
    while(flag!=0)
    {
        switch(flag)
        {
            case 1: {                      
                       int c;
                       cin>>b>>c;
                       switch(b)
                       {
                         case 1:a.add(c);break;
                         case 2:a.deleted(c);break;
                         case 3:a.find(c);break;
                        }
                       break;
                    }
            case 2:{                    
                       float c;
                       cin>>b>>c;
                       switch(b)
                       {
                         case 1:a2.add(c);break;
                         case 2:a2.deleted(c);break;
                         case 3:a2.find(c);break;
                        }
                       break;
                    }
            case 3:{              
                       string c;
                       cin>>b>>c;
                       switch(b)
                       {
                         case 1:a3.add(c);break;
                         case 2:a3.deleted(c);break;
                         case 3:a3.find(c);break;
                        }
                       break;
                    }
        }        
        cin>>flag;
    }
    return 0;
}

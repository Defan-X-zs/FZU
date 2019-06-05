//7-6 复数相乘--运算符重载
#include<iostream>
using namespace std;
class complex
{
    private:
        int real;
        int imag;
    public:
        void set(int r,int i)
        {
            real=r;
            imag=i;
        }
        friend complex operator *(complex &c1,complex &c2);
        void display();

};

complex operator *(complex &c1,complex &c2)
{
    int re,im;
    complex c3;
    c3.real=c1.real*c2.real-(c1.imag*c2.imag);
    c3.imag=c1.real*c2.imag+c1.imag*c2.real;
    return c3;
}
void complex::display()
{
    if(imag<0)
    {
        if(imag==-1)
        {           
            if(real==0)
            {
                cout<<"-i"<<endl;
            }
            else
            {
                cout<<real<<"-i"<<endl;
            }

        }
        
        else
        {
            if(real==0)
            {
                cout<<imag<<"i"<<endl;
            }
            else
            {
                cout<<real<<imag<<"i"<<endl;
            }
        }
    }
    
    else if(imag>0)
    {
        if(imag==1)
        {
            if(real==0)
            {
                cout<<"i"<<endl;
            }
            else

            {
                cout<<real<<"+i"<<endl;
            }
        }
        
        else
        {
            if(real==0)
            {
                cout<<imag<<"i"<<endl;
            }
            else
            {
                cout<<real<<"+"<<imag<<"i"<<endl;
            }
        }

    }
    
    if(imag==0)
    {
        cout<<real<<endl;
    }

}

int main()
{
    complex a,b,c;
    string str[3];
    int re[20]= {0},im[20]= {0};
    for(int i=0; i<2; i++)
    {
        int count5=1;
        cin>>str[i];
        int o=0;
        int k=-1;
        
        if(str[i][str[i].size()-1]!='i')
        {
            for(int l=str[i].size()-1; l>=0; l--)
            {
                re[i]=str[i][l]-'0';
            }
        }
        
        else
        {
            for(int j=0; j<str[i].size(); j++)
            {

                if(str[i][j]=='-')
                {
                    k=j;
                }
                if(str[i][j]=='+')
                {
                    o=1;
                }
            }
            
            if(o==0&&k==-1)
            {
                re[i]=0;
                
                if(str[i][str[i].size()-1]==str[i][0])
                {
                    im[i]=1;
                }
                
                else
                {
                    for(int l=str[i].size()-2; l>=0; l--)
                    {
                        im[i]+=(str[i][l]-'0')*count5;
                        count5*=10;
                    }
                }
                
            }
            
            else if(o==0&&k==0)
            {
                if(str[i]=="-i")
                {
                    im[i]=1;
                }
                else
                {
                    for(int l=str[i].size()-2; l>0; l--)
                    {
                        im[i]+=(str[i][l]-'0')*count5;
                        count5*=10;
                    }
                }
                im[i]=-1*im[i];
                
            }

            else
            {
                for(int j=0; j<str[i].size(); j++)
                {
                    int count1=1;
                    int count2=1;
                    int count3=1;
                    int count4=1;
                    if(str[i][j]=='+')
                    {
                        for(int t=j-1; t>=0; t--)
                        {
                            re[i]+=(str[i][t]-'0')*count1;
                            count1*=10;
                        }
                        if(str[i][j+1]=='i')
                        {
                            im[i]=1;
                        }
                        else
                        {
                            for(int t=str[i].size()-2; t>j; t--)
                            {
                                im[i]+=(str[i][t]-'0')*count2;
                                count2*=10;
                            }
                        }

                    }
                    if(str[i][j]=='-'&&j!=0)
                    {
                        for(int t=j-1; t>=0; t--)
                        {
                            re[i]+=(str[i][t]-'0')*count3;
                            count3*=10;
                        }
                        if(str[i][j+1]=='i')
                        {
                            im[i]=1;
                        }
                        else
                        {
                            for(int t=str[i].size()-2; t>j; t--)
                            {
                                im[i]+=(str[i][t]-'0')*count4;
                                count4*=10;
                            }
                        }
                        im[i]=-1*im[i];
                    }
                    if(str[i][0]=='-')
                    {
                        re[i]=-1*re[i];
                    }
                }

            }
        }
    }
    a.set(re[0],im[0]);
    b.set(re[1],im[1]);
    c=a*b;
    c.display();
    return 0;
}
//6-1 大整数求和（运算符重载）
class BigInt

{

private:

    string str;

public:

    BigInt() {}

    BigInt(string s)

    {

        str=s;

    }

 

    friend ostream&operator<<(ostream &os, BigInt &bigint)

    {

        os<<bigint.str;

        return os;

    }

    friend istream&operator>>(istream &is,BigInt &bigint)

    {

        is>>bigint.str;

        return is;

    }

    friend BigInt operator+( BigInt &bigint1, BigInt &bigint2);

};

 

BigInt operator+( BigInt &bigint1, BigInt &bigint2)

{

    string a=bigint1.str;

    string b=bigint2.str;

    string temp;

    if(a.size()>b.size())

    {

        temp=a;

        a=b;

        b=temp;

    }  ///b是长数字

 

    char *sum=new char[b.size()+2];

    int carry=0;//记录进位

    int count=0;//记录sum的长度，从0开始

    int m,n,k;//m,n取出a,b的某一位

    int al,bl;//指示当前数字的位置

    for (al=a.size()-1,bl=b.size()-1; al>=0; al--,bl--)

    {

        m=a[al]-'0';

        n=b[bl]-'0';

        k=m+n+carry;

        if(k > 9)

        {

            carry=1;

            k-=10;

            sum[count]=k+'0';

        }

        else

        {

            sum[count]=k+'0';

            carry=0;

        }

        count++;

    }

    if(a.size()==b.size() && carry==1) sum[count]='1';//判断位数相等的情况

    if(a.size()==b.size() && carry==0)  count--;//用于最后封口，指示封口位置

 

    int sizeDif=b.size()-a.size();//当a,b不等时，记录位差

    int i=sizeDif-1;

    for(bl!=0; i>=0; i--)  //a,b不等的情况

    {

        k=b[i]-'0'+carry;

        if(k>9)

        {

            carry=1;

            k-=10;

            sum[count]=k+'0';

 

        }

        else

        {

            sum[count]=k+'0';

            carry=0;

        }

        count++;

        if(i==0 && carry==1) sum[count]='1';  //检测首位是否需要进位

        if(i==0 && carry==0) count--;

    }

    sum[count+1]='\0';//封口

    int j;

    char t;

    int x=count;

    for(j=0; j<=count/2; j++)//交换输出，注意count是从0开始记录的

    {

 

        t=sum[j];

        sum[j]=sum[x];

        sum[x]=t;

        x--;

    }

    string st(sum);//将字符数组转换为字符串

    return BigInt(st);

}

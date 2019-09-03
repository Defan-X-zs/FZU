//6-9 整数的素因子分解
bool prime(int p)
{
    int i;
    if(p<=1) return false;
    for(i=2; i<=sqrt(p); i++)
        if(p%i==0) return false;
    return true;
}

void Solution::solve()
{
    int a[30],i,j=0,b=n;
    if(prime(b)) cout<<b<<"="<<b<<endl;
    else
    {
        for(i=2; ; )
            if(prime(i) && b%i==0 )
            {
                a[j++]=i;
                b/=i;
                if(b==1) break;
            }
            else i++;
        cout<<n<<"=";
        for(i=0; i<j-1; i++) cout<<a[i]<<"*";
        cout<<a[i]<<endl;
    }
}


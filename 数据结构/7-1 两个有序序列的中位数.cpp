#include<iostream>//7-1 两个有序序列的中位数
using namespace std;
int main()
{
	int n, i, j, k;
	cin>>n;
	int a[n], b[n], c[2*n];
	for(i = 0; i < n; i++) cin>>a[i];
	for(i = 0; i < n; i++) cin>>b[i];
    for(i = 0, j = 0, k = 0; i < 2*n; i++) 
	{
        if(j != n && k != n) 
		{ 
			if(a[j] <= b[k]) 
			{
				c[i] = a[j];
                j++;
            }
            else 
			{
				c[i] = b[k];
                k++;
            }
        }
        else if (j != n && k == n) 
		{
			c[i] = a[j];
            j++;
        }
        else if (j == n && k != n) 
		{
        
			c[i] = b[k];
            k++;
        }
        else break;
    }
    cout<<c[(i-1) / 2];
}

#include<iostream>//7-8 矩阵转置
using namespace std;
int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<a[0][i]<<" "<<a[1][i]<<" "<<a[2][i]<<endl;
    }
    return 0;
}

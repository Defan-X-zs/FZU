#include <iostream>//7-4 二维数组每行排序
using namespace std;
int main()
{
    int i, n, j, k, b, p, x, y;
    int a[4][5];
    for(i=0; i<4; i++) {
    	for(n=0; n<5; n++) {
    	cin>>a[i][n];
    	}
	}
	for(p=0; p<4; p++) {//p行数 
		for(j=0; j<5; j++) {//j列数 
			for(k=0; k<5-j-1; k++){//k判定每一列元素的比对次数 
				if(k<5 && a[p][k] > a[p][k+1]) {
					b = a[p][k];
					a[p][k] = a[p][k+1];
					a[p][k+1] = b;
				}
			}	
		}
	}
    for(x=0; x<4; x++){
    	for(y=0; y<5; y++){
    	cout<<"   "<<a[x][y];
    }
    cout<<endl;
	}
    return 0;
}

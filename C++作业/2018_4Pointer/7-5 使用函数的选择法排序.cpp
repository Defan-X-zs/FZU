#include <iostream>//7-5 使用函数的选择法排序

using namespace std;

void sort(int a[], int n )
{	
	for(int i = 0; i < n; i++ ) {
		int min =i;
		for(int j = i+1; j < n; j++) {
			if (a[j] < a[min])	
				min = j;
		}		
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

int main()
{
	int i, repeat, n, x;
    int a[10];
    cin>>repeat;
    while(repeat--) {
    	cin>>n;
    for(i = 0; i < n; i++)
        cin>>a[i];
    sort(a, n);
    cout<<"After sorted:";
	for(i = 0; i < n; i++)	
		cout<<" "<<a[i];
	cout<<endl;
    }  
}

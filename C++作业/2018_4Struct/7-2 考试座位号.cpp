#include <iostream>//7-2 考试座位号

using namespace std;

typedef struct
{
	string id1;
	int id2; 
	int id3;  
} stu;

int main()
{
	int n, m;
	cin>>n;
	stu s[n];
	for(int i = 0; i < n; i++) {
		cin>>s[i].id1>>s[i].id2>>s[i].id3;
	}
	
	cin>>m;
	int a[m];
	for(int i = 0; i < m; i++) {
		cin>>a[i];
	}
	int i, j;
	for(j = 0; j < m; j++) {
		for(i = 0; i < n; i++) {
			if (s[i].id2 == a[j]) 
			cout<<s[i].id1<<" "<<s[i].id3<<endl;
		}
	}
  	return 0;
}

#include <iostream>//7-1 输入学生信息

using namespace std;

typedef struct
{
	int number; 
	double score;  
} stu;

int main()
{
	int n;
	cin>>n;
	stu s[10];
	for(int i = 0; i < n; i++) {
		cin>>s[i].number>>s[i].score;
	}
	for(int i = 0; i < n; i++) {
		cout<<s[i].number<<" "<<s[i].score<<endl;
	}
  	return 0;
}

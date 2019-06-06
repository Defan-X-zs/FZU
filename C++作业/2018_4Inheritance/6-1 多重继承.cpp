//6-1 多重继承
#include <iostream>
using namespace std;
class Teacher{
private:
	string name;
	int age;
	string title;
public:
	Teacher(string n, int a, string t):name(n),age(a),title(t){}
	string getname(){return name;}
	int getage(){return age;}
	string gettitle(){return title;}
};
class Student{
private:
	string name;
	int age;
	double score;
public:
	Student(string n, int a, double s):name(n),age(a),score(s){}
	double getscore(){return score;}
};
class Graduate:public Teacher, public Student{  
public:
	Graduate(string n, int a, char sex, string t, double s, float w):Teacher(n, a, t),Student(n, a, s),sex(sex),wages(w){}    
	void show(){
		cout<<"name:"<<getname()<<endl<<"age:"<<getage()<<endl<<"sex:"<<getsex()<<endl<<"score:"<<getscore()<<endl<<"title:"<<gettitle()<<endl<<"wages:"<<getwages();
	}
	float getwages(){return wages;}
	char getsex(){return sex;}
private:      
	float wages;
	char sex;
};

#include <iostream>//Class Student 1.0
#include <string>
using namespace std;
class Cstudent { 
	private:
 		int ID;
 		string name;
 		int age;
 		char gender;
 		float scores[6];
 		float averagescore;
 		float gradescore;
	public:
		Cstudent();
 		Cstudent(int stuid,string stuname,
		 char stugender,int stuage);
 		Cstudent(const Cstudent &stu);
 		~Cstudent(){;}
 		void SetName(string stuname);
 		void SetID(int stuid);
 		void SetGender(char stugender);
 		void SetAge(int stuage);
 		void average_score();
 		void displayinfo();
 		void inputscores();
 		string getname();
 		void grade_compute();
 		void ResetInfo(int stuid, string stuname, char stugender, int stuage);
};
int main()
{ 
 	Cstudent Stu1(303001, "zhang", 'M', 21);
 	Cstudent Stu2(Stu1);
 	Cstudent Stu3;
 	string name; 
 	name=Stu1.getname();
 	Stu1.inputscores();
	Stu1.average_score();
 	Stu1.grade_compute();
 	Stu1.displayinfo(); 
 	Stu2.ResetInfo(303002, "LI", 'F',20);
 	Stu2.inputscores();
 	Stu2.average_score();
 	Stu2.grade_compute();
 	Stu2.displayinfo();
 	Stu3.SetID(303003);
 	Stu3.SetName("LI");
 	Stu3.SetGender('F');
 	Stu3.SetAge(22);
 	Stu3.inputscores();
 	Stu3.average_score();
 	Stu3.grade_compute();
 	Stu3.displayinfo();
 	return 0; 
}
Cstudent::Cstudent() {
	ID = 0;
	name = " ";
	age = 0;
	gender = ' ';
} 
Cstudent::Cstudent(const Cstudent &stu) {
	ID = stu.ID;
 	name = stu.name;
 	age = stu.age;
 	gender = stu.gender;
}
Cstudent::Cstudent(int stuid,string stuname,
 					char stugender,int stuage) {
	ID = stuid;
 	name = stuname;
 	age = stuage;
 	gender = stugender;	
}
void Cstudent::SetName(string stuname) {
	name = stuname;	
}
void Cstudent::SetID(int stuid) {
	ID = stuid;
}
void Cstudent::SetGender(char stugender) {
	gender = stugender;
}
void Cstudent::SetAge(int stuage) {
	age = stuage;
}
string Cstudent::getname() {
	return name;
}
void Cstudent::inputscores() {
	for (int i = 0; i < 6; ++i)
	{
		cin>>scores[i];
	}
}
void Cstudent::average_score() {
	float sum = 0;
	for (int i = 0; i < 6; ++i)
	{
		sum += scores[i];	
	}
	averagescore = sum / 6.0;
}
void Cstudent::ResetInfo(int stuid, string stuname, char stugender, int stuage) {
	ID = stuid;
	name = stuname;
	gender = stugender;
	age = stuage;
}
void Cstudent::grade_compute() {
	gradescore = 4.0;
}
void Cstudent::displayinfo() {
 	cout<<ID<<" "
 	<<name<<" "
 	<<gender<<" "
 	<<age<<" "
 	<<averagescore<<" "
 	<<gradescore<<endl;
 	cout<<"detail scores:";
 	for (int i = 0; i < 6; i++)
 	cout<<scores[i]<<" ";
 	cout<<endl;
}

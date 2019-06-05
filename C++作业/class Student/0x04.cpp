#include <iostream>//Class Student 4.0
#include <string>
using namespace std;
class Cstudent { 
	private:
 		int ID;
 		string name;
 		int age;
 		char gender;
 		float averagescore;
 		//float gradescore;
	public:
		float scores[11];
		//static float scorebase[6];
		//static void setscorebase(float s1, float s2, float s3, float s4, float s5, float s6);
		Cstudent();
 		Cstudent(int stuid,string stuname,
		 char stugender,int stuage);
 		~Cstudent(){;}
 		void SetName(string stuname);
 		void SetID(int stuid);
 		void SetGender(char stugender);
 		void SetAge(int stuage);
 		void average_score();
 		friend void max();
 		friend void min();
 		void displayinfo();
 		void inputscores();
 		string getname();
 		void setCS_student(int stuid, string stuname, char stugender, int stuage);
 		void grade_compute();
 		void ResetInfo(int stuid, string stuname, char stugender, int stuage);
};
float Min[11], Max[11];
Cstudent CS_student[300];
int main()
{
 	//Cstudent::setscorebase(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
 	CS_student[1].setCS_student(303001, "zhang", 'M', 21);
 	CS_student[1].inputscores();
 	CS_student[1].average_score();
 	//CS_student[1].grade_compute();
 	CS_student[1].displayinfo(); 
 	CS_student[2].SetID(303002);
 	CS_student[2].SetName("lin");
 	CS_student[2].SetGender('F');
 	CS_student[2].SetAge(22);
 	CS_student[2].inputscores();
 	CS_student[2].average_score();
 	//CS_student[2].grade_compute();
 	CS_student[2].displayinfo();
 	return 0;
}
Cstudent::Cstudent() {
	ID = 0;
	name = " ";
	age = 0;
	gender = ' ';
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
	for (int i = 0; i < 11; ++i)
	{
		cin>>scores[i];
	}
}
void Cstudent::average_score() {
	float sum = 0;
	for (int i = 0; i < 11; ++i)
	{
		sum += scores[i];	
	}
	averagescore = sum / 11.0;
}
void Cstudent::ResetInfo(int stuid, string stuname, char stugender, int stuage) {
	ID = stuid;
	name = stuname;
	gender = stugender;
	age = stuage;
}
/*void Cstudent::grade_compute() {
	float sum = 0;
	for (int i = 0; i < 11; ++i)
	{
		sum += scores[i] * scorebase[i];
	}
	gradescore = sum / 10 - 5;
}*/
void Cstudent::setCS_student(int stuid, string stuname, char stugender, int stuage) {
	ID = stuid;
	name = stuname;
	gender = stugender;
	age = stuage;
}
/*void Cstudent::setscorebase(float s1, float s2, float s3, float s4, float s5, float s6) {
	scorebase[1] = s1;scorebase[2] = s2;scorebase[3] = s3;
	scorebase[4] = s4;scorebase[5] = s5;scorebase[6] = s6;
}*/
void Cstudent::displayinfo() {
 	cout<<ID<<" "
 	<<name<<" "
 	<<gender<<" "
 	<<age<<" "
 	<<averagescore<<" "
 	<</*gradescore<<*/endl;
 	cout<<"detail scores:";
 	for (int i = 0; i < 11; i++)
 	cout<<scores[i]<<" ";
 	cout<<endl;
}
void max() {
	int i, j;
	for (i = 0; i < 11; ++i)
	{
		Max[i] = 0;
		for (j = 0; j < 300; j++) {
			if(CS_student[j].scores[i]>Max[i]) {
			Max[i] = CS_student[j].scores[i];
			}
		}
	}
}
void min() {
	int i, j;
	for (i = 0; i < 11; ++i)
	{
		Min[i] = 101;
		for (j = 0; j < 300; j++) {
			if(CS_student[j].scores[i]<Min[i]) {
			Min[i] = CS_student[j].scores[i];
			}
		}
	}
}

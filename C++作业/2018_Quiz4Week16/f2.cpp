//f2
#include <iostream>
using namespace std;
class Animal{
	protected:
		int age;
		public:
			Animal(int a):age(a){}
			int getAge(){
				return age;
			}
};
class Dog : public Animal{
	protected:
		string color;
		public:
			Dog(int a , string c):Animal(a),color(c){}
			void showInfor(){
				cout<<"age:"<<getAge()<<endl;
				cout<<"color:"<<color;
			}
};
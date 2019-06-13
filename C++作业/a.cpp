:People(id, name),sid(sid),score(score){
	
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

class Animal{
	private:
		int m_nWeightBase;
	protected:
		int m_nAgeBase;
	public:
		Animal(){
		}
		void set_weight(int w){
			m_nWeightBase = w;	
		}
		int get_weight(){
			return m_nWeightBase;
		}
		void set_age(int a){
			m_nAgeBase = a;
		}
};
class Cat:public Animal{
	private:
		string m_strName;
	public:
		Cat(string n):m_strName(n){}
		void print_age(){
			cout<<m_strName<<", age = "<<m_nAgeBase<<endl;
		}
};

class Animal{
	private:
		int m_nWeightBase;
	protected:
		int m_nAgeBase;
	public:
		Animal(){
		}
		void set_weight(int w){
			m_nWeightBase = w;	
		}
		int get_weight(){
			return m_nWeightBase;
		}
		void set_age(int a){
			m_nAgeBase = a;
		}
};
class Cat:public Animal{
	private:
		string m_strName;
	public:
		Cat(string n):m_strName(n){}
		void set_print_age(){
			set_age(5);
			cout<<m_strName<<", age = "<<m_nAgeBase<<endl;
		}
		void set_print_weight(){
			set_weight(6);
			cout<<m_strName<<", weight = "<<get_weight()<<endl;
		}
};

//请实现Account构造函数Account(char *name)
//请实现Account的PrintUserName()函数
//请实现CreditAccount类的构造函数CreditAccount(char* name, long number)
//请实现CreditAccount类的PrintInfo()函数
Account::Account(string name):userName(name){}
void Account::PrintUserName(){
	cout<<userName<<endl;
}
CreditAccount::CreditAccount(string name, int credit):Account(name),credit(credit){}
void CreditAccount::PrintInfo(){
	PrintUserName();
	cout<<credit;
}	

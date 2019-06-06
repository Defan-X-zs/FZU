//6-2 派生类的定义和使用
class Animal
{
public:
	void speak(){cout<<"animal language!";}
};
class Cat:public Animal
{
public:
	Cat(string s):m_strName(s){}
	void print_name(){
		cout<<"cat name: "<<m_strName<<endl;
	}
private:
	string m_strName;
};
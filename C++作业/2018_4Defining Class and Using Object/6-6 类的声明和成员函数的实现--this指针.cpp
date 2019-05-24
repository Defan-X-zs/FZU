//6-6 类的声明和成员函数的实现--this指针
class Car {
	public:
		void disp_welcomemsg();
		int get_wheels();
		void set_wheels(int);
	private:
		int m_nWheels;
};
void Car::disp_welcomemsg() {
	cout<<"Welcome to the car world!"<<endl; 
} 
int Car::get_wheels() {
	return m_nWheels;
}
void Car::set_wheels(int a) {
	m_nWheels = a;
}  


//f3
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
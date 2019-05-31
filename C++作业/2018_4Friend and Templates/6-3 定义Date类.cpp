//6-3 ¶¨ÒåDateÀà
class Date{
	public:
		Date(int m, int d, int y);
		Date(int m, int d);
		Date(int m);
		Date();
		void display();
	private:
		int month, day, year;
};
void Date::display(){
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
Date::Date(int m, int d, int y){
	month = m;
	day = d;
	year = y;
} 
Date::Date(int m, int d){
	month = m;
	day = d;
	year = 2019;
}
Date::Date(int m){
	month = m;
	day = 1;
	year = 2019;
}
Date::Date(){
	month = 1;
	day = 1;
	year = 2019;
}

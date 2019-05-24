//6-11 时钟类
class Clock {
	public:
		Clock() {
			hour = 0;
			minute = 0;
			second = 0;
		}
		Clock(int a,int b,int c) {
			hour = a;
			minute = b;
			second = c;
		}
		void showTime() {
			cout<<hour<<":"<<minute<<":"<<second<<endl;
		}
	private:
		int hour=0, minute=0, second=0;
};

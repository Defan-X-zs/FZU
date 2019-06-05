//6-3 学生成绩的输入和输出（运算符重载）
class Student{
	private:
		string name;
		int score;
		int id;
	public:
		friend ostream & operator<<(ostream &, Student &);
		friend istream & operator>>(istream &, Student &);		
};
ostream & operator <<(ostream & output, Student & obj) {
	output<<obj.id<<". "<<obj.name<<" ";
	if (obj.score >= 60) output<<"PASS";
	else output<<"FAIL";
	return output;
}
int NO = 0;
istream & operator >>(istream & input, Student & obj) {
	input>>obj.name>>obj.score;
	obj.id = ++NO;
	return input;
}

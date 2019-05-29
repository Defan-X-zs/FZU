//6-2 ѧ���ɼ��Ŀ���¼�루���캯����
class Student
{
	public:
		Student(int no, int score)
		{
			m_No = no;
			m_score = score;
			count++;
		}
		Student(const Student& s)
		{
			this->m_No = s.m_No + 1;
			this->m_score = s.m_score;
			count++;
		}
		~Student()
		{
			count--;
		}
		void display()
		{
			cout << m_No << " " << (m_score ? "Pass" : "Fail") << endl;
		}
		static int count;
	private:
		int m_No;
		int m_score;
};
int Student::count = 0;

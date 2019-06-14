//f5
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

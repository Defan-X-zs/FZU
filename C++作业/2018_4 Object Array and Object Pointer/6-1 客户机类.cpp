//6-1 客户机类
#include <iostream> 
#include <stdio.h>
using namespace std;
class Client{
	public:
		Client();
		static char ServerName;
		static int ClientNum;
		static void changeServerName(char a);
		static void show();	
}; 
char Client::ServerName = 'A';
int Client::ClientNum = 0;
void Client::changeServerName(char a) {
	ServerName = a;		
}
Client::Client() {
	Client::ClientNum ++;
}
void Client::show() {
	cout<<"server name:"<<Client::ServerName<<endl;
	cout<<"num of clients:"<<Client::ClientNum<<endl;
}		


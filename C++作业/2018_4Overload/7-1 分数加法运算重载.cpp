//7-1 分数加法运算重载
#include <iostream>
using namespace std;
class FS{
private:
	int fz;
	int fm;
public:
	FS(){}
	FS(int z, int m):fz(z),fm(m){}
	void set(int x, int y) {
		fz = x;
		fm = y;
	}
	int measure(int x, int y);
	void show() 
	{
		cout<<fz<<"z"<<fm<<"m"<<endl;
	}
	FS operator + (const FS &f)
	{
		int y = fm*f.fm;
		int x = (fz*f.fm)+(f.fz*fm);
		int a = measure(x, y);
		x = x / (a * 1.0);
		y = y / (a * 1.0);
		if (y<0)
		{
			x = -x;
			y = -y;
		}
		return FS(x, y);
	}
};
int main (){
	int n;
	cin>>n;
	int i;
	int fz, fm;
	char a, b;
	FS *f = new FS[2*n];
	FS *f1 = new FS[n];
	for (i = 0; i < 2*n;i++)
	{
		cin>>fz>>a>>fm>>b;
		f[i].set(fz, fm);
	}
	int j = 0;
	for (i = 0; i < 2*n; i++)
	{
		f1[j] = f[i] + f[i + 1];
		i++;j++;
	}
	for (i = 0; i < n; ++i)
	{
		f1[i].show();
	}
}
int FS::measure(int x, int y){
	int z = y;
	while (x%y!=0) {
		z = x%y;//辗转相除法
		x = y;
		y = z;
	}
	return z;
}

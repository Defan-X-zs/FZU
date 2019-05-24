//6-3 方阵的转置
#include <iostream>

using namespace std;

class Matrix{
	public:
		void input() {
			for(int i = 0; i < 9; i++) {
				cin>>a[i];
			}
		}
		void show() {
			cout<<"datas:"<<endl;
			cout<<' '<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
			cout<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<endl;
			cout<<' '<<a[6]<<' '<<a[7]<<' '<<a[8]<<endl;
		}
		void transform() {
			int temp;
			temp = a[1]; a[1] = a[3]; a[3] = temp;
			temp = a[2]; a[2] = a[6]; a[6] = temp;
			temp = a[5]; a[5] = a[7]; a[7] = temp;
		}
		int a[9];
};


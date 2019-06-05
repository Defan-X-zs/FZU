//7-2 矩阵的乘法运算
#include <iostream>
using namespace std;
class matrix {
	private:
		int row;
		int colume;
		int **mat;
	public:
		matrix(){}
		matrix(int r, int c){
			int mat[r][c];
		}
		void set(int i, int j, int t){
			mat[i][j] = t;
		}
		int getr(){
			return row;
		}
		int getc(){
			return colume;
		}
		void display(){
			//cout<<setw(10)<<mat[i][j];
		}
		friend matrix operator * (matrix &m1, matrix &m2);
};
int main() {
	int r1, c1;
	cin>>r1>>c1;
	matrix m1(r1, c1);
	int i, j, t;
	for(i = 0; i < r1; i++){
		for(j = 0; j < c1; j++){
			cin>>t;
			m1.set(i, j, t);
		}
	}
	int r2, c2;
	cin>>r2>>c2;
	matrix m2(r2, c2);
	for(i = 0; i < r2; i++){
		for(j = 0; j < c2; j++){
			cin>>t;
			m2.set(i, j, t);
		}
	}
	if(m1.getc == m2.getr) {
		m3 = m1 * m2;
		m3.display();
	}
	else{
		cout<<"Invalid Matrix multiplication!"<<endl;
	}
}
matrix operator * (matrix &m1, matrix &m2){
	matrix m;
}
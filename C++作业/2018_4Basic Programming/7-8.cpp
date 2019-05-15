#include <iostream>//7-8 掉入陷阱的数字
using namespace std;
int sum(int n) {
    int result, sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    result = 3 * sum + 1;
    return result;
}
int main()
{		
	int num, i, result, temp;
	cin>>num;
    temp = num;
    for(i = 1; ; i++) {
        result = sum(temp);
        cout<<i<<":"<<result<<endl;
        if(temp == result) {
            break;
        }
        temp = result;
    }
    return 0;
}


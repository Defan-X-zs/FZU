int ArrayShift( int a[], int n, int m )//6-1 数组循环右移
{
	int temp;
	while(m--) {
		temp = a[n-1];
		for(int j=n-1; j>=1; j--) {
			a[j]=a[j-1];
		} 
		a[0] = temp;
	} 
	return a;
}
 

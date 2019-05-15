void sort(int a[], int n )//6-2 使用函数的选择法排序 
{	
	for(int i = 0; i < n; i++ ) {
		int max =i;
		for(int j = i+1; j < n; j++) {
			if (a[j] > a[max])	
				max = j;
		}		
		int temp = a[max];
		a[max] = a[i];
		a[i] = temp;
	}
}


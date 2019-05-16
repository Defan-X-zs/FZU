#include <stdio.h>//7-4 在数组中查找指定元素

int search(int list[], int n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if (list[i] == x)
		{
			return i;
			break;
		}
	}
	return -1;
}

int main()
{
    int i, index, repeat, n, x;
    int a[10];
    scanf("%d", &repeat);
    while(repeat--) {
    	scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    index = search( a, n, x);
    if(index != -1 )
        printf("index = %d\n", index);
    else
        printf("Not found\n");
	}
}


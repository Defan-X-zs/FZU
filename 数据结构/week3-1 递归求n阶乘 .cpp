//µÝ¹éÇón½×³Ë 
#include<stdio.h>
int factTR(int n, int a)
{
    if (n == 0)
        return a;
    return factTR(n - 1, a*n);/*Î²µÝ¹é*/
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", factTR(n, 1));
    return 0;
}

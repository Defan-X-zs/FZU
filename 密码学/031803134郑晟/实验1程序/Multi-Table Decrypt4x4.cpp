#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 4
int gcd(int a,int b) 
{
    return b==0?a:gcd(b,a%b);
}

int getdet(int A[4][4])
{
    int det=-1;
    for(int p = 1; det < 0; p++)
        {
            det = ((A[0][0]*A[1][1]*A[2][2]*A[3][3] + A[0][1]*A[1][2]*A[2][3]*A[3][0] + A[1][3]*A[2][0]*A[0][2]*A[3][1] + A[0][3]*A[1][0]*A[2][1]*A[3][2] 
                  - A[3][0]*A[2][1]*A[1][2]*A[0][3] - A[2][0]*A[1][1]*A[0][2]*A[3][3] - A[1][0]*A[0][1]*A[3][2]*A[2][3] - A[0][0]*A[3][1]*A[2][2]*A[1][3] + 26 * p) % 26); 
        }
    return det;
}

int A[4][4];
void get_A() 
{
	srand(time(NULL));
    int det;
    do {
    	A[0][0] = rand() % 26;
        A[0][1] = rand() % 26;
        A[0][2] = rand() % 26;
        A[0][3] = rand() % 26;
        A[1][0] = rand() % 26;
        A[1][1] = rand() % 26;
        A[1][2] = rand() % 26;
        A[1][3] = rand() % 26;
        A[2][0] = rand() % 26;
        A[2][1] = rand() % 26;
        A[2][2] = rand() % 26;
        A[2][3] = rand() % 26;
        A[3][0] = rand() % 26;
        A[3][1] = rand() % 26;
        A[3][2] = rand() % 26;
        A[3][3] = rand() % 26;
    	det = getdet(A);
    } while(gcd(det, 26) != 1);
    
    printf("\nRandon 4x4 A:\n");
    for(int i = 0; i < 4; i++)
	{
    	for(int j = 0; j < 4; j++)
		{
    		printf("%d ", A[i][j]);
		}
    	printf("\n");
    }
	putchar('\n');
}

int A_verse[4][4],A_com[4][4];
int inv(int x)
{
	int i = 1;
 	while(1)
	{	
 		if((x * i) % 26 == 1)
		{
 			x = i;
 			break;
		}
 		else i++;
	} 
	return i;
}
int getA(int arcs[N][N],int n)//按第一行展开计算|A|  
{  
    if(n==1)  
    {  
        return arcs[0][0];  
    }  
    int ans = 0;  
    int temp[N][N];  
    int i,j,k;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n-1;j++)  
        {  
            for(k=0;k<n-1;k++)  
            {  
                temp[j][k] = arcs[j+1][(k>=i)?k+1:k];  
                  
            }  
        }  
        int t = getA(temp,n-1);//递归调用
        if(i%2==0)  
        {  
            ans += arcs[0][i]*t;  
        }  
        else  
        {  
            ans -=  arcs[0][i]*t;  
        }  
    }  
    return ans;  
}  
void getAStart(int A[N][N],int n,int A_com[N][N])//计算每一行每一列的每个元素所对应的余子式，组成A*  
{  
    if(n==1)  
    {  
        A_com[0][0] = 1;  
        return;  
    }  
    int i,j,k,t;  
    int temp[N][N];  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            for(k=0;k<n-1;k++)  
            {  
                for(t=0;t<n-1;t++)  
                {  
                    temp[k][t] = A[k>=i?k+1:k][t>=j?t+1:t];  
                }  
            }  
            A_com[j][i]  =  getA(temp,n-1);  
            if((i+j)%2 == 1)  
            {  
                A_com[j][i] = - A_com[j][i];  
            }  
        }  
    }  
}  
void get_A_verse(int A[4][4], int A_verse[4][4])
{
    int det_A;
    det_A = getdet(A);
    int det_A_verse = inv(det_A);
    getAStart(A, 4,A_com);
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            A_verse[i][j] = (A_com[i][j]*det_A) % 26;
        }
    } 
    for(int i = 0; i < 4; i ++){
    	for(int j = 0; j < 4; j++){
    		A_verse[i][j] = (A_verse[i][j] + 26) % 26;
    	}
    }  
	printf("\nA_verse:\n");
    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 4; j++){
    		printf("%d ",A_verse[i][j]);
    	}
    	printf("\n");
    }
    putchar('\n');
}

int B[4];
void get_B()
{
    do {
 		for (int i = 0; i < 4; i++)
 		B[i] = rand() % 25;
 	} while(B[1] == 0 && B[2] == 0 && B[0] == 0 && B[3] == 0);
 	printf("Randon Key B:\n");
	printf("%d %d %d %d\n", B[0], B[1], B[2], B[3]);
	putchar('\n');
}

char cleartext[600]={0};
char ciphertext[600]={0};
void encode(char cleartext[600], int A[4][4], int B[4], char ciphertext[600])
{
    int temp[600]={0};//存放转换成数字的明文
    int flag=0, m[4]={0,0,0,0};
    printf("请输入明文:");scanf("%s",cleartext);
    int len = strlen(cleartext);
    for(int i = 0; i < len; i++)
    {
    	/*if(cleartext[i] >= 'A' && cleartext[i] <= 'Z')
        {
            temp[i] = cleartext[i] + 32;
        }*/
    	temp[i] = cleartext[i] - 'a';
    	//printf("%d ",temp[i]);
	}
    /*if(len % 3 == 2)
    {
        cleartext[len] = cleartext[len-1];
        temp[len] = temp[len-1];
        len ++;
        flag=1;
    }*/
    for(int i = 0; i < len; i += 4)
    {   
        m[0] = (A[0][0] * temp[i] + A[0][1]*temp[i+1] + A[0][2]*temp[i+2]+ A[0][3]*temp[i+3] + B[0] ) % 26;
        m[1] = (A[1][0] * temp[i] + A[1][1]*temp[i+1] + A[1][2]*temp[i+2]+ A[1][3]*temp[i+3] + B[1] ) % 26;
        m[2] = (A[2][0] * temp[i] + A[2][1]*temp[i+1] + A[2][2]*temp[i+2]+ A[2][3]*temp[i+3] + B[2] ) % 26; 
        m[3] = (A[3][0] * temp[i] + A[3][1]*temp[i+1] + A[3][2]*temp[i+2]+ A[3][3]*temp[i+3] + B[3] ) % 26;          
        temp[i] = m[0];
        temp[i+1] = m[1];
        temp[i+2] = m[2];
        temp[i+3] = m[3];
	}
    /*if(flag == 1)
    {
        len = len - 1;
    }*/
    printf("\n密文:");
    for(int i = 0; i < len; i++)
	{
        ciphertext[i]=temp[i] + 'a';
		putchar(temp[i] + 'a');    
	}
	putchar('\n');
}

void decode(char ciphertext[600], int A_verse[4][4], int B[4], char cleartext[600])
{
    int temp[600] = {0}; //存储转换后的密文 
	int flag=0, m[4] = {0,0,0,0};
	int len = strlen(ciphertext);
    for(int i = 0; i < len; i++)
    {
        /*if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            temp[i] = ciphertext[i] + 32;
        }*/
    	temp[i] = ciphertext[i] - 'a';
    }
    /*if(len % 3 == 2)//5位的情况 
    {
    	ciphertext[len] = ciphertext[len-1];
    	temp[len] = temp[len-1];
        len ++;
        flag = 1;
    }*/
    for(int i = 0; i < len; i += 4)
    {    
        m[0] = (A_verse[0][0]*(temp[i]-B[0]) + A_verse[0][1]*(temp[i+1]-B[1]) + A_verse[0][2]*(temp[i+2]-B[2]) + A_verse[0][3]*(temp[i+3]-B[3])+2600) % 26;
        m[1] = (A_verse[1][0]*(temp[i]-B[0]) + A_verse[1][1]*(temp[i+1]-B[1]) + A_verse[1][2]*(temp[i+2]-B[2]) + A_verse[1][3]*(temp[i+3]-B[3])+2600) % 26;
        m[2] = (A_verse[2][0]*(temp[i]-B[0]) + A_verse[2][1]*(temp[i+1]-B[1]) + A_verse[2][2]*(temp[i+2]-B[2]) + A_verse[2][3]*(temp[i+3]-B[3])+2600) % 26; 
        m[3] = (A_verse[3][0]*(temp[i]-B[0]) + A_verse[3][1]*(temp[i+1]-B[1]) + A_verse[3][2]*(temp[i+2]-B[2]) + A_verse[3][3]*(temp[i+3]-B[3])+2600) % 26;      
        temp[i] = m[0];
        temp[i+1] = m[1];
        temp[i+2] = m[2];
        temp[i+3] = m[3];
		while(temp[i]<0) temp[i]+=26;
		while(temp[i+1]<0) temp[i+1]+=26;
		while(temp[i+2]<0) temp[i+2]+=26;  
        while(temp[i+3]<0) temp[i+3]+=26; 
    }	
    /*if(flag == 1)
    {
        len = len - 1;
    }*/
    for(int i = 0; i < len; i++)
	{
        ciphertext[i] = temp[i] + 'a';
	}
	printf("\n明文：%s\n", cleartext);
}
int main()
{
	printf("多表代换加解密\n");
	get_A();
	get_B();
	encode(cleartext, A, B, ciphertext);
	get_A_verse(A, A_verse);
	decode(ciphertext, A_verse, B, cleartext);
	printf("\n-----Good Bye-----"); 
	return 0;
}
//defanive

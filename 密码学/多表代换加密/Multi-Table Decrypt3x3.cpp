#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int gcd(int a,int b) 
{
    return b==0?a:gcd(b,a%b);
}
int A[3][3];
void get_A() 
{
	srand(time(NULL));
    int det;
    do {
    	A[0][0] = rand() % 26;
        A[0][1] = rand() % 26;
        A[0][2] = rand() % 26;
        A[1][0] = rand() % 26;
        A[1][1] = rand() % 26;
        A[1][2] = rand() % 26;
        A[2][0] = rand() % 26;
        A[2][1] = rand() % 26;
        A[2][2] = rand() % 26;
    	det = -1;
        for(int p = 1; det < 0; p++)
        {
            det = ((A[0][0]*A[1][1]*A[2][2] + A[0][1]*A[1][2]*A[2][0] + A[1][0]*A[2][1]*A[0][2] 
				  - A[1][1]*A[2][0]*A[0][2] - A[0][1]*A[1][0]*A[2][2] - A[0][0]*A[1][2]*A[2][1] + 26 * p) % 26); 
        }
    } while(gcd(det, 26) != 1);
    
    printf("\nRandon 3x3 A:\n");
    for(int i = 0; i < 3; i++)
	{
    	for(int j = 0; j < 3; j++)
		{
    		printf("%d ", A[i][j]);
		}
    	printf("\n");
    }
	putchar('\n');
}

int A_verse[3][3];
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
void get_A_verse(int A[3][3], int A_verse[3][3])
{
    int det_A;
    det_A = ((A[0][0]*A[1][1]*A[2][2] + A[0][1]*A[1][2]*A[2][0] + A[1][0]*A[2][1]*A[0][2] - A[1][1]*A[2][0]*A[0][2] - A[0][1]*A[1][0]*A[2][2] - A[0][0]*A[1][2]*A[2][1] + 26 * 1000) % 26);
    int det_A_verse = inv(det_A);
    A_verse[0][0] = det_A_verse * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) % 26;
    A_verse[0][1] = det_A_verse * (A[0][1] * A[2][2] - A[0][2] * A[2][1]) * (- 1) % 26;
    A_verse[0][2] = det_A_verse * (A[0][1] * A[1][2] - A[0][2] * A[1][1]) % 26;
    A_verse[1][0] = det_A_verse * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) * (- 1) % 26;
    A_verse[1][1] = det_A_verse * (A[0][0] * A[2][2] - A[0][2] * A[2][0]) % 26;
    A_verse[1][2] = det_A_verse * (A[0][0] * A[1][2] - A[0][2] * A[1][0]) * (- 1) % 26;
    A_verse[2][0] = det_A_verse * (A[1][0] * A[2][1] - A[1][1] * A[2][0]) % 26;
    A_verse[2][1] = det_A_verse * (A[0][0] * A[2][1] - A[0][1] * A[2][0]) * (- 1) % 26;
    A_verse[2][2] = det_A_verse * (A[0][0] * A[1][1] - A[0][1] * A[1][0]) % 26;
    for(int i = 0; i < 3; i ++){
    	for(int j = 0; j < 3; j++){
    		A_verse[i][j] = (A_verse[i][j] + 26) % 26;
    	}
    }  
	printf("\nA_verse:\n");
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		printf("%d ",A_verse[i][j]);
    	}
    	printf("\n");
    }
    putchar('\n');
}

int B[3];
void get_B()
{
    do {
 		for (int i = 0; i < 3; i++)
 		B[i] = rand() % 25;
 	} while(B[1] == 0 && B[2] == 0 && B[0] == 0);
 	printf("Randon Key B:\n");
	printf("%d %d %d\n", B[0], B[1], B[2]);
	putchar('\n');
}

char cleartext[600]={0};
char ciphertext[600]={0};
void encode(char cleartext[600], int A[3][3], int B[3])
{
    int temp[600]={0};//存放转换成数字的明文
    int flag=0, m[3]={0};
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
    for(int i = 0; i < len; i += 3)
    {   
        m[0] = (A[0][0] * temp[i] + A[0][1]*temp[i+1] + A[0][2]*temp[i+2] + B[0] ) % 26;
        m[1] = (A[1][0] * temp[i] + A[1][1]*temp[i+1] + A[1][2]*temp[i+2] + B[1] ) % 26;
        m[2] = (A[2][0] * temp[i] + A[2][1]*temp[i+1] + A[2][2]*temp[i+2] + B[2] ) % 26;          
        temp[i] = m[0];
        temp[i+1] = m[1];
        temp[i+2] = m[2];
	}
    /*if(flag == 1)
    {
        len = len - 1;
    }*/
    printf("\n密文:");
    for(int i = 0; i < len; i++)
	{
		putchar(temp[i] + 'a');    
	}
	putchar('\n');
}

void decode(char cleartext[600], int A_verse[3][3], int B[3])
{
    int temp[600] = {0}; //存储转换后的密文 
	int flag=0, m[3] = {0,0,0};
    printf("请输入密文：");
    scanf("%s", ciphertext);
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
    for(int i = 0; i < len; i += 3)
    {    
        m[0] = (A_verse[0][0]*(temp[i]-B[0]) + A_verse[0][1]*(temp[i+1]-B[1]) + A_verse[0][2]*(temp[i+2]-B[2] )) % 26;
        m[1] = (A_verse[1][0]*(temp[i]-B[0]) + A_verse[1][1]*(temp[i+1]-B[1]) + A_verse[1][2]*(temp[i+2]-B[2] )) % 26;
        m[2] = (A_verse[2][0]*(temp[i]-B[0]) + A_verse[2][1]*(temp[i+1]-B[1]) + A_verse[2][2]*(temp[i+2]-B[2] )) % 26;       
        temp[i] = m[0];
        temp[i+1] = m[1];
        temp[i+2]= m[2];
		if(temp[i]<0) temp[i]+=26;
		if(temp[i+1]<0) temp[i+1]+=26;
		if(temp[i+2]<0) temp[i+2]+=26;  
    }	
    /*if(flag == 1)
    {
        len = len - 1;
    }*/
    for(int i = 0; i < len; i++)
	{
        ciphertext[i] = temp[i] + 'a';
	}
	printf("\n明文：%s\n", ciphertext);
}

void getA()
{
	printf("\n输入3x3 A矩阵：\n");
	scanf("%d %d %d\n", &A[0][0], &A[0][1], &A[0][2]);
	scanf("%d %d %d\n", &A[1][0], &A[1][1], &A[1][2]);
	scanf("%d %d %d", &A[2][0], &A[2][1], &A[2][2]);
	/*for(int j = 0; j < 3; j++)
		printf("%d %d %d\n", A[j][0], A[j][1], A[j][2]);
	*/ 
}
void getB()
{
	printf("\n输入B：\n");
	scanf("%d %d %d", &B[0], &B[1], &B[2]);
	//printf("%d %d %d\n", B[0], B[1], B[2]);
}

int main()
{
	int option;
	printf("多表代换加解密\n\n1.加密     2.解密\n\n请选择功能(Enter确认)：");
	scanf("%d", &option);
	if(option == 1)
	{
		get_A();
		get_B();
		encode(cleartext, A, B);
		printf("\n-----Good Bye-----");
	}
	else if(option ==2)
	{	
		getA();
		getB();
		get_A_verse(A, A_verse);
		decode(ciphertext, A_verse, B);
		printf("\n-----Good Bye-----");
	}
	else printf("\n-----Good Bye-----"); 
	return 0;
}
//defanive
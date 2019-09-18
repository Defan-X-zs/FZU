#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#define M 3   //定义一下三阶矩阵
int gcd(int a, int b){
	return b==0?a : gcd(b, a%b);
}

int main()
{
   FILE *fp;
   FILE *fp1;
   int i,j,det,invdet,len,flag,len1=0;
   int A[M][M]={0},comA[M][M]={0},invA[M][M]={0},B[M]={0},tran1[10000]={0},T1[3]={0},cip[3]={0},s[10000]={0};
   int msg[3]={0},mes[10000]={0},x[3]={0};
   int T2[3]={0},tran2[10000]={0};
   char pla[10000]={'\0'}; //明文
   char ciph[10000]={'\0'}; //密文
   char plas[10000]={'\0'}; //对密文解密后的明文
   
   //产生满足条件的随机三阶矩阵A
   srand(time(0));
   do{
      for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            A[i][j]=rand()%26; 
		} 
	  }
	  det = -1;
      for(i=1; det < 0; i++)
        {
            det = ((A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[0][1]*A[1][2]*A[2][0]-A[0][2]*A[1][1]*A[2][0]-A[0][0]*A[1][2]*A[2][1]-A[0][1]*A[1][0]*A[2][2]) + 26 * i)%26; //行列式的表达式
        }
	  
   }while(gcd(det,26)!=1||det==0);   //行列式必须不等于0并且与26互素

   printf("Encryption matrix A: \n");
   for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",A[i][j]); 
        } 
        printf("\n"); 
    } //输出生成的A矩阵

   i = 1;
   while(1)
        {
            if((det * i) % 26 == 1)
            {
                invdet = i;
                break;
            }
            else
            {
                i++;
            }
   } //求三阶矩阵A的行列式的逆元为invdet
   

    //以下为求A的伴随矩阵
	comA[0][0] = (A[1][1] * A[2][2] - A[2][1] * A[1][2]);
	comA[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
	comA[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
	comA[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
	comA[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
	comA[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
    comA[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
	comA[1][2] = -(A[0][0] * A[1][2] - A[0][2] *A[1][0]);
	comA[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    //以下求A的逆矩阵
    for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			invA[i][j]=invdet*comA[i][j];  
			invA[i][j] %= 26;
			if (invA[i][j] < 0) invA[i][j] += 26;
		}
	}

	//以下生成B矩阵
	do{
        for (i = 0; i < 3; i++)
		{
            B[i]=rand()%25;
		}
	}while(B[1]==0&&B[2]==0&&B[0]==0);
     printf("In this experiment,we use Key B as follows:\n");
     printf("%d %d %d\n",B[0],B[1],B[2]);

   fp = fopen("plain.txt", "r"); //  r打开只读文件，该文件必须存在,plain文件中存放着需要进行加密的字符
   i=0;
   while(!feof(fp))  //将文件中的字符一个一个读入到char型的pla数组中
	{
       pla[i]=fgetc(fp);
	   i++;
	}  
	len=strlen(pla)-1;   //使用这样方式读写数组最后一个会多出一个空格，我们在操作中需要丢弃这个空格，所以strlen(pla)-1才是实际的长度

    if(len % 3 == 2)   //填充
	 {
            pla[len] = 'a';
            len = len+1;
            flag = 1;
     }
    if(len % 3 == 1)   //填充
	 {
            pla[len] = 'a';
            len = len+1;
            pla[len] = 'a';
            len = len+1;
            flag = 2;
     }


	//加密
    // 将大写转成小写，并赋值给tran1数组(次数组是int型的数组，存放的是输入明文字符对应的数值，例如a和A对应的是0，z和Z对应的是25，以此类推)
     for(i=0; i<len; i++)
        {
            if(pla[i] >= 'A' && pla[i] <= 'Z')
            {
                pla[i] = pla[i] + 32;
            }
            tran1[i] = pla[i] - 'a';
        }
     for(i=0; i<len; i=i+3)
        {
            T1[0] = tran1[i];
            T1[1] = tran1[i + 1];
            T1[2] = tran1[i + 2];
            // cip存储密文int值
            cip[0] = ((A[0][0]*T1[0]+A[0][1]*T1[1]+A[0][2]*T1[2])+B[0]) % 26;
            cip[1] = ((A[1][0]*T1[0]+A[1][1]*T1[1]+A[1][2]*T1[2])+B[1]) % 26;
            cip[2]= ((A[2][0]*T1[0]+A[2][1]*T1[1]+A[2][2]*T1[2])+B[2]) % 26;
            s[i] = cip[0];
            s[i + 1] = cip[1];
            s[i + 2] = cip[2];
        }
    //准备输出解密密文,将这些密文都放入到ciph数组中，此时ciph数组内的元素个数一定是3的倍数
      for(i=0; i<len; i++)
        {
            ciph[i] = s[i] + 'a';   
        }
    //将密文打印在屏幕上	  
      printf("The encoded Ciphertext：\n");
      if(flag == 1)    //如果在加密的过程中添加了一位，在显示的时候，少显示一位即可
	  {                //将加密后的密文显示出来（不带有扩展位）
            len1 = len - 1;
            for(i=0; i<len1; i++){
				printf("%c",ciph[i]);
			}
	  }
      else if(flag==2){   
            len1 = len - 2;
            for(i=0; i<len1; i++){
				printf("%c",ciph[i]);
			}
	  }
	  else {
          for(i=0; i<len; i++){
				printf("%c",ciph[i]);
			}
	  }
	  //其实上述过程只是保证密文与原明文长度一致，并无其他意义，因为多表代换密码中，明文与密文是三个三个对应的，不存在一一对应关系。 
     
	  printf("\n");
      printf("The encoded Ciphertext： \n");
	  //将密文输入到文本文件内
     fp1 = fopen("output.txt", "w");
	 i=0;
     while(ciph[i]!='\0' )
	 {fprintf(fp1,"%c",ciph[i]);
       i++;
	 } 


     //下面是对上面的密文开始解密
	 len=strlen(ciph);   //此时的len依旧是3的倍数
     for(i=0; i<len; i++)
        {
            tran2[i] = ciph[i] - 'a';
        }
    // 得到解密后的明文 
        for(i=0; i<len; i=i+3)
        {
            T2[0] = tran2[i];
            T2[1] = tran2[i + 1];
            T2[2] = tran2[i + 2];
	        x[0]=T2[0]-B[0];   //x矩阵计算C-B的值
	        x[1]=T2[1]-B[1];
            x[2]=T2[2]-B[2];
            // msg存储明文int值
            msg[0] = (x[0]*invA[0][0]+x[1]*invA[0][1]+x[2]*invA[0][2]) % 26;
            msg[1] = (x[0]*invA[1][0]+x[1]*invA[1][1]+x[2]*invA[1][2]) % 26;
            msg[2] = (x[0]*invA[2][0]+x[1]*invA[2][1]+x[2]*invA[2][2]) % 26;
			if(msg[0]<0) msg[0]+=26;
            if(msg[1]<0) msg[1]+=26;
            if(msg[2]<0) msg[2]+=26;
			//mes矩阵接受解密后得到的明文的ascll码值
            mes[i] = msg[0];
            mes[i+1]=msg[1];
			mes[i+2]=msg[2];
        }
    //准备输出解密后的明文
     printf("After decoding,the plain text ：\n");
        for(i=0; i<len; i++)
        {
            plas[i] = mes[i] + 'a';
        }
     if(flag == 1)
        {
            len = len - 1;
            for(i=0; i<len; i++){
				printf("%c",plas[i]);
        }
      printf("\n");
	 }
	 else if(flag == 2)
        {
            len = len - 2;
            for(i=0; i<len; i++){
				printf("%c",plas[i]);
        }
      printf("\n");
	}
	 else
	 {
              for(i=0; i<len; i++){
				  printf("%c",plas[i]);}
            printf("\n");
	 }
}

char *search( char *s, char *t )//6-10 查找子串
{
	char *s1=s; // s1为每次比较主串的开始处
    char *p=s1, *q=t;
    while(*s1){
        while(*q){
            if(*p == *q){
                p++;
                q++;
            }
            else
                break; // 子串未遍历完，遇不等字符
        }
        if( (*p != *q)&&(*q) ){
        // 内循环因字符不等退出，且子串未到结束标志处，继续比较
            s1++;
            p = s1;
            q = t;
        }
        else
            break; // 已找到,跳出外循环
    }
    if(*s1=='\0') // 若外循环因主串走到结束标志处而退出，则未找到
        s1 = NULL;
    return s1;
}


  


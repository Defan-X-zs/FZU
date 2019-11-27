#include<iostream>//7.11 前缀游戏
#include<string.h>
#include<algorithm>
using namespace std;
int trie[400000][26],len,root,tot,sum[400000];
int n,m; 
char s[11];
int search()
{
    root=0;
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'a';
        if(!trie[root][id]) return 0;
        root=trie[root][id];
    }//root经过此循环后变成前缀最后一个字母所在位置
    return sum[root];
}
void insert()
{
    len=strlen(s);
    root=0;
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'a';
        if(!trie[root][id]) trie[root][id]=++tot;
        sum[trie[root][id]]++;//前缀保存 
        root=trie[root][id];
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        insert();
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s;
        cout<<search();
    }
}

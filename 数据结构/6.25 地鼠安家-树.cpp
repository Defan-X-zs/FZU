#include<stdio.h>//6.25 地鼠安家-树
const int maxn = 10001;
static int t = 0,lson[maxn],rson[maxn],index[maxn],a[maxn];
void bstreeJudge(int x)
{
    if (x != -1)
    {
        bstreeJudge(lson[x]);
        a[t++] = x;
        bstreeJudge(rson[x]);
    }
}
int bstreeHeight(int x)
{
    if (x == -1)return -1;
    int lh = bstreeHeight(lson[x]);
    int rh = bstreeHeight(rson[x]);
    return lh>rh?++lh:++rh;
}
int main()
{
    int n,l_value,r_value,father;
    for(int i = 0; i < n; i++) lson[i]=-1,rson[i]=-1,index[i]=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &l_value, &father, &r_value);
        lson[father] = l_value;
        rson[father] = r_value;
        index[l_value]++;
        index[r_value]++;
    }
    int root;
    for(int i = 1; i <= n; i++)
    {
        if (!index[i])
        {
            root = i;
            break;
        }
    }
    bstreeJudge(root);
    int flag = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1] + 1)
        {
            flag = 1;
            break;
        }
    }
    if(flag) printf("%d", -1);
        else printf("%d", bstreeHeight(root)+1);
    return 0;
}

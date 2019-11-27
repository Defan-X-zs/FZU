#include<iostream>//10.1 比赛结果-拓扑排序
#include<memory.h>
using namespace std;
const int NUM = 505;
int g[NUM][NUM], degreein[NUM], ans[NUM], N, M;
void toposort()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(g[i][j])
                degreein[j]++;

    for(int i = 1; i <= N; i++) 
    {
        int k = 1;
        while(degreein[k] != 0)
            k++;
        ans[i] = k;
        degreein[k] = -1;
        for(int j = 1; j <= N; j++)
            if(g[k][j])
                degreein[j]--;
    }
}
int main()
{
        // 初始化
        memset(g, 0, sizeof(g));
        memset(degreein, 0, sizeof(degreein));
        memset(ans, 0, sizeof(ans));
        cin>>N>>M;
        // 读入数据
        int u, v;
        for(int i = 1; i <= M; i++) {
            cin>>u>>v;
            g[u][v] = 1;
        }
        // 拓扑排序
        toposort();
        // 输出结果
        for(int i = 1; i < N; i++)
            cout<<ans[i]<<" ";
        cout<<ans[N]<<endl;
    return 0;
}

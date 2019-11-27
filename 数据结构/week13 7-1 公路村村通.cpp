#include<iostream>//7-1 公路村村通
#include <bits/stdc++.h>
using namespace std;
int g[1005][1005], cost[1005], N, M;
bool b[1005];
const int INF=0x3f3f3f3f;
void prim()
{
	memset(b, false, sizeof(b));
	memset(cost, INF, sizeof(cost));
	cost[1] = 0;
	bool flag = false;
	int res = 0;
	while(true)
	{
		int v = -1;
		for(int u = 1; u <= N; u++)
		{
			if(!b[u]&&(v==-1||cost[u]<cost[v]))
			{
				v = u;
			}
		}
		if(v == -1)break;
		b[v] = true;
		if(cost[v]==INF)
		{
			flag = true;
			break;
		}
		res += cost[v];
		for(int u = 1; u <= N; u++)
		{
			cost[u] = min(cost[u], g[u][v]);
		}
	}
	if(flag) cout<<"-1";
    else cout<<res;
}
int main()
{
	for(int i = 0; i<1005; i++) memset(g[i], INF, sizeof(g[i]));
	cin>>N>>M;
	for(int i = 0; i < M; i++)
	{
		int x, y, c;
        cin>>x>>y>>c;
		g[x][y] = c;
		g[y][x] = c;
	}	
	prim();
	return 0;
}

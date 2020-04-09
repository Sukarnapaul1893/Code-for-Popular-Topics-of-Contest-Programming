#include<bits/stdc++.h>
#define PII pair<int, int>
#define mp make_pair
using namespace std;

const int N=505;
int INF=1e7;

vector<PII> adj[N];     //node cost
int dis[N];
bool vis[N];

void clear()
{
    fill (adj, adj + N, vector<PII> ());
    fill (dis, dis + N, INF);
    fill (vis, vis + N, false);
}

void Dijkstra (int s)
{
    dis[s]=0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push(mp(0,s));

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        //cout<<d<<" "<<u<<" "<<endl;
        pq.pop();

        if (vis[u])  continue;
        vis[u]=1;
        assert ( d == dis[u]);

        for (int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int c = adj[u][i].second;
            int cur = max (dis[u], c);

            if (cur < dis[v])
                dis[v] = cur,
                pq.push(mp(cur, v));
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    for (int cs=1; cs<=t; cs++)
    {
        clear();
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i=0; i<m; i++)
        {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            adj[y].push_back( mp (x, c));
            adj[x].push_back( mp (y, c));
        }

        int s;
        scanf("%d", &s);
        Dijkstra(s);

        printf("Case %d:\n", cs);
        for (int i=0; i<n; i++)
            if (dis[i] == INF)  printf("Impossible\n");
            else                printf("%d\n",  dis[i]);

    }
}

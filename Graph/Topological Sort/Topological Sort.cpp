#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;

bool vis[10005];
vector<int>adj[10005];

vector<int>topsort;

void dfs(int source){
    vis[source]=true;
    for(int i=0;i<adj[source].size();i++){
        if(vis[adj[source][i]]==false){
            vis[adj[source][i]]=true;
            dfs(adj[source][i]);
        }
    }
    topsort.pb(source);
}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    memset(vis,false,sizeof vis);

    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i);
        }
    }
    for(auto it=topsort.rbegin();it!=topsort.rend();it++){
        cout<<(*it)<<" ";
    }
}

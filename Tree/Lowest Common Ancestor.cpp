// Solution of SPOJ-POLICEMEN
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
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

#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;

int par[MAXN][LG];



vector<int>adj[10005];
vector<int>adj2[MAXN];
bool vis[10005];
int level[10005];
int lca(int u, int v){
	if(level[u] < level[v])	swap(u, v);
	int log = log2(level[u]);
	for(int i = log; i >= 0; i--)
		if(level[u]-level[v] >= (1 << i))
			u = par[u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}


void dfs(int u, int parent){
	level[u] = level[parent] + 1;
	par[u][0] = parent;
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}




int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    memset(vis,false,sizeof vis);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(par, -1, sizeof par);
    level[0] = -1;
    dfs(1, 0);
    for(int j = 1; j < LG; j++){
    	for(int i = 1; i <= n; i++){
    		if(par[i][j-1] != -1)
    			par[i][j] = par[par[i][j-1]][j-1];
    	}
    }


    int q;
    cin>>q;
    while (q--) {
    int u, v;
    cin>>u>>v;
    if(level[u]>=level[v]){
        cout<<"YES ";
    }
    else{
        cout<<"NO\n";
        continue;
    }


    cout << lca(u,v) << '\n';

  }
}

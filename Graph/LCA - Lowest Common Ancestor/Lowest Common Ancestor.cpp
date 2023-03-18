/* 
    Based on SPOJ-POLICEMEN problem 
    Problem:
        Given a rooted tree and some queries. 
        In each queries, there are two nodes.
        Compare their distance from their lowest common ancestor 
        and make decision.
*/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;

int par[MAXN][LG];
int n;
vector<int>adj[10005];
vector<int>adj2[MAXN];
bool vis[10005];
int level[10005];

void input();

void dfs(int u, int parent){
	level[u] = level[parent] + 1;
	par[u][0] = parent;
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}

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

void queries(){
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

void calculateAncestors(){
    memset(par, -1, sizeof par);
    level[0] = -1;  // level of root 
    dfs(1, 0);
    for(int j = 1; j < LG; j++) {
    	for(int i = 1; i <= n; i++) {
    		if(par[i][j-1] != -1)
    			par[i][j] = par[par[i][j-1]][j-1];
    	}
    }
}

void solve(){
    calculateAncestors();
    queries();
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    solve();
    Clear();

}

void input(){
    cin>>n;
    memset(vis,false,sizeof vis);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
}

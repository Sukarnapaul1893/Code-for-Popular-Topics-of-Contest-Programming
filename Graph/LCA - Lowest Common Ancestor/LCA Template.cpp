const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;

int par[MAXN][LG];

vector<int>adj[50005];

bool vis[50005];
int level[50005];

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
void CallMeToFindLCA(){
    memset(par, -1, sizeof par);
    level[0] = -1;
    dfs(0, -1);  //0-indexed
    for(int j = 1; j < LG; j++){
    	for(int i = 1; i <= n; i++){
    		if(par[i][j-1] != -1)
    			par[i][j] = par[par[i][j-1]][j-1];
    	}
    }
}

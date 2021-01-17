// Kosaraju's Algorithm (2-DFS Algorithm) for finding SCC in a directed graph

/*
Take input and make a graph with adjacency lists adj[].
Then also make a graph reversing all those given edges with adjacency list adjb[]

Run dfs TopsortDfs() from all unvisited nodes from 1 to n. 
Here a node unvisited means it is not visted in any of previous TopsortDfs() call.
Now reverse the topsort vector.

Run dfs BackEdgeDfs() for the reverse-edge graph adjb[] from all unvisited nodes in the topsort vector from left to right.
The number of Strongly Connected Components will be the number of times you have to call BackEdgeDfs() from topsort vector.

For bengali tutorial : 

*/

int n;      //number of nodes

vector<int>adj[2003];   
vector<int>adjb[2003];    //back-edge adjacency list

int vis[2003];        
int visb[2003];           //for back-edge

vector<int>topsort;

// Simply finds the topological sort of a graph
void TopsortDfs(int v){
    vis[v]++;

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(vis[u]==0)TopsortDfs(u);
    }

    topsort.pb(v);
}

// DFS fucntion of the reverse-edge graph
void BackEdgeDfs(int v){
    visb[v]++;

    for(int i=0;i<adjb[v].size();i++){
        int u = adjb[v][i];
        if(visb[u]==0)BackEdgeDfs(u);
    }
}

int scc;      // The number of strongly connected components

void CountScc(){
    for(int i=0;i<topsort.size();i++){
        int u = topsort[i];
        if(visb[u] == 0){
            BackEdgeDfs(u);     scc++;
        }
    }
}


void input();

void solve(){
    for(int i=1;i<=n;i++){
        if(vis[i]==0)TopsortDfs(i);
    }

    reverse(topsort.begin(),topsort.end());
    CountScc();

    cout<<scc<<"\n";
}

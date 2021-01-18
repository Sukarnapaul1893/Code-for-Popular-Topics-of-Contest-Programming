//detect cycle in a directed graph

/* initially all vertices are colored 0. 
   Now when dfs starts from some vertex, we will color it to 1.
   Then when dfs ends from that vertex , we will color it to 2.
   If at some point, we come to some vertex which is already colored by 1, it will mean that there is a cycle.
*/

#define MAXN 100005

vector<int>adj[MAXN];
int color[MAXN];
bool cycle;         // initialize it with false

void dfs(int v){
    if(color[v] == 0){
        color[v] = 1;
        for(auto u : adj[v]){
            dfs(u);
        }
        color[v] = 2;
    }
    else if(color[v] == 1){
        cycle = true;
    }
}

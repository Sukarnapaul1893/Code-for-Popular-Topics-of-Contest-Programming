#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int>adj[200005];
bool vis[200005];


int e[2];   //e[0] , e[1] are the ending points
int cur;

int mx;
void dfs(int s, int d){

    vis[s]=true;

    if(mx<=d){
        e[cur]=s;
        mx=d;
    }
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];

        if(vis[u]==false){
            dfs(u,d+1);
        }
    }
}


int main(){
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);

    }
    memset(vis,false,sizeof vis);
    dfs(1,0);
    mx=0;
    cur++;
    memset(vis,false,sizeof vis);
    dfs(e[0],0);
    cout<<e[0]<<"\n";
    cout<<e[1]<<"\n";
}

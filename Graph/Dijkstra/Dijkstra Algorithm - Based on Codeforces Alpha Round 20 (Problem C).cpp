#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v)              ((v).begin()), ((v).end())
using namespace std;
int n;
int pp[100005];
ll dist[100005];
vector<pii > mt[100005];
void dijkstra(int src){


	for (int i = 2; i <= n; ++i) {
		dist[i] =(1LL<<62);
	}

	set<pair<int, int> > q;
	q.insert(make_pair(0, 1));
	while(!q.empty()){
		int u = (*q.begin()).second;
		q.erase(q.begin());
		for (int j = 0; j < mt[u].size(); ++j) {
			if (dist[u]+mt[u][j].second < dist[mt[u][j].first]){
				dist[mt[u][j].first] = dist[u]+mt[u][j].second;
				pp[mt[u][j].first] = u;
				q.insert(make_pair(dist[mt[u][j].first], mt[u][j].first));
			}

		}
	}

}

void solve(int node)
{
	if (node!=1)
		solve(pp[node]);
	cout<<node<<" ";
}
int main(){

	int e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mt[u].pb(mkp(v,w));
		mt[v].pb(mkp(u,w));
	}
	dijkstra(1);
	if(pp[n]){
        solve(n);
	}
	else{
        cout<<"-1";
	}
}

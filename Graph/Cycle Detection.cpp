void Detect_Cycle(int v, int parent){
    vis[v] = true;
    st.pb(v);

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(u==parent)continue;
        if(vis[u]==true){
            while(true){
                int x  = st.back();
                st.pop_back();
                cycle.pb(x);
                in_cycle[x]=1;
                if(x==u)break;
            }
            found = true;
            return;
        }

        Detect_Cycle(u,v);

        if(found)return;
    }
    st.pop_back();
}

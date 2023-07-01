pair<int,int> dfs(int v, int par, int depth) {
    parentOf[v] = par;
    pair<int,int> deepestNode = {v,depth};
    for(int i=0;i<adjacencyList[v].size();i++) {
        int u = adjacencyList[v][i];
        if(u!=par) {
            auto nextDeepestNode = dfs(u,v,depth+1);
            if(nextDeepestNode.second > deepestNode.second) {
                deepestNode = nextDeepestNode;
            }
        }
    }
    return deepestNode;
}

pair<int,int> findDiameterEndNodes() {
    int d1 = dfs(1, -1, 0).first;
    int d2 = dfs(d1, -1, 0).first;
    return {d1, d2};
}

void findDiameterPath(int d1, int d2) {
    int currentNode = d2;
    
    while(parentOf[currentNode]!=-1) {
        isOnDiameterPath[currentNode] = true;
        diameterPath.push_back(currentNode);
        currentNode = parentOf[currentNode];
    }
    diameterPath.push_back(d1);
    isOnDiameterPath[d1] = true;
    reverse(diameterPath.begin(), diameterPath.end());
}
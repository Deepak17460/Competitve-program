bool IsCycle_dfs(int node,int parent,unordered_map<int,bool>&visited, unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto neigbhour:adj[node]){
        if(!visited[neigbhour]){
            bool ans=IsCycle_dfs(neigbhour,node,visited,adj);
            if(ans==1) return true;
        }
        else if(neigbhour!=parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adj;
    // preparing the adj
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //unordered_map<int,int>parent;
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
        bool ans=IsCycle_dfs(i,-1,visited,adj);
            if(ans==1)
                return "Yes";
          }
        }
   return "No";
}

Time complexity is again Linear as per the dfs traversal technique
i.e O(N+E)
where N is the node & E is the edge

class Solution {
public:

    bool dfs(int node,int destination,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        if(node==destination) return true;
        

        for(auto it:adj[node]){
            if(vis[it]!=1){
                if(dfs(it,destination,adj,vis))
                return true;
            }
        }

        return false;

        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        vector<int>vis(n);

      for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      return dfs(source,destination,adj,vis);
    }
};

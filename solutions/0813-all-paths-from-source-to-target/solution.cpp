class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,vector<int>&vis, vector<int>& temp,
             vector<vector<int>>& ans) {
        vis[node] = 1;
        temp.push_back(node);
        if (node == adj.size() - 1) {
            ans.push_back(temp);
            return;
        }

        for(auto it:adj[node]){
           if(vis[it]!=1){
            dfs(it,adj,vis,temp,ans);
            vis[it]=0;
            temp.pop_back();
           }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> vis(n);
        vector<int> temp;

        dfs(0, graph, vis, temp, ans);

        return ans;
    }
};

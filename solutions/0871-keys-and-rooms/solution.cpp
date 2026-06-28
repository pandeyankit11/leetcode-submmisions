class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &n,int &cnt) {
        vis[node] = 1;
        cnt++;
        if (cnt == n)
            return true;

        for (auto it : adj[node]) {
            if (vis[it] != 1) {
                if (dfs(it, adj, vis, n, cnt))
                    return true;
            }
        }

        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int cnt = 0;
        vector<int> vis(n);

        return dfs(0, rooms, vis, n, cnt);
    }
};

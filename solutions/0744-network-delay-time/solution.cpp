class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        	vector<vector<pair<int, int>> > adj(n+1);
		for (auto& edge : times) {
			int u = edge[0];
			int v = edge[1];
			int weight = edge[2];
			
			adj[u].push_back({v, weight});
			
			
		}
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		vector<int> dist(n+1, 1e9);
		dist[k] = 0;
		
		pq.push({0, k});
		
		while (!pq.empty()) {
			int currDis = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			
			if (currDis > dist[node])
				continue;
			
			for (auto it : adj[node]) {
				int adjNode = it.first;
				int edgeWeight = it.second;
				
				if (currDis + edgeWeight < dist[adjNode]) {
					dist[adjNode] = currDis + edgeWeight;
					pq.push({dist[adjNode], adjNode});
				}
			}
		}

        int maxTime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)
            return -1;
            maxTime=max(maxTime,dist[i]);
        }

        return maxTime;
		
    }
};

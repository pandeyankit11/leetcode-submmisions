class DisjointSet {

public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges=0;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUParent(u)==ds.findUParent(v))
            extraEdges++;
            else{
                ds.unionBySize(u,v);
            }

        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
            cntC++;
        }

        
        if(extraEdges>=cntC-1) return cntC-1;
        return -1;
    }
};

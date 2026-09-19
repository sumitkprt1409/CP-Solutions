class Solution {
    public:
    struct DSU{
        vector<int> rank, parent;

        DSU(int n){
            rank.resize(n);
            parent.resize(n);

            for(int i=0; i<n; i++){
                rank[i] = 0;
                parent[i] = i;
            }
        }

        int find_parent(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = find_parent(parent[node]);
        }

        void UnionByRank(int a, int b){
            int Ulp_a = find_parent(a);
            int Ulp_b = find_parent(b);

            if(Ulp_a == Ulp_b){
                return;
            }
            else if(rank[Ulp_a] < rank[Ulp_b]){
                parent[Ulp_a] = Ulp_b;
            }
            else{
                parent[Ulp_b] = Ulp_a;
                rank[Ulp_a]++;
            }
        }

    };

public:


    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra_edges = 0;
        DSU ds(n);
        for(auto x : connections){
            int a = x[0];
            int b = x[1];

            if(ds.find_parent(a) == ds.find_parent(b)){
                extra_edges++;
            }
            else{
                ds.UnionByRank(a, b);
            }
        }

        int no_connection = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                no_connection++;
            }
        }

        int ans = no_connection - 1;

        if(extra_edges >= ans){
            return ans;
        }

        return -1;


    }
};
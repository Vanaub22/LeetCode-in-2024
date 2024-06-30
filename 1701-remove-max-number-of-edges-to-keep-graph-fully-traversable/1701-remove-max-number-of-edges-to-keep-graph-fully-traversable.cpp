// Data structure to perform Disjoint Set Union operation by size
class DSU {
    vector<int> size,parent;
    public:
    DSU(int n) {
        size.resize(n+1,1);
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
    }
    int findPar(int node) {
        return parent[node]=node==parent[node]?node:findPar(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int pu=findPar(u),pv=findPar(v);
        if(pu==pv) return false;
        if(pu<pv) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu_alice(n),dsu_bob(n);
        int removed_edges=0,alice_edges=0,bob_edges=0;
        // Handling the type-3 edges first because they can be used by both Alice and Bob
        for(auto& edge:edges) {
            int type=edge[0],u=edge[1],v=edge[2];
            if(type==3) {
                // Ensuring that both the union operations are performed once
                bool alice_used=dsu_alice.unionBySize(u,v),bob_used=dsu_bob.unionBySize(u,v);
                if(alice_used || bob_used) alice_edges++,bob_edges++;
                else removed_edges++;
            }
        }
        // Handling the type-1 and type-2 edges
        for(auto& edge:edges) {
            int type=edge[0],u=edge[1],v=edge[2];
            if(type==1) {
                if(dsu_alice.unionBySize(u,v)) alice_edges++;
                else removed_edges++;
            }
            else if(type==2){
                if(dsu_bob.unionBySize(u,v)) bob_edges++;
                else removed_edges++;
            }
        }
        return alice_edges==n-1 && bob_edges==n-1?removed_edges:-1;
    }
};

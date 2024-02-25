class Solution {
private:
    void dfs(int node, bool vis[], auto g[]) {
        if(vis[node]) return;
        vis[node]=true;
        for(int i:g[node]) dfs(i,vis,g);
    }
    vector<int> primeFactorization(int x) {
        vector<int> primeFactorization;
        for(int i=2;i*i<=x;i++) if(x%i==0) {
            primeFactorization.push_back(i);
            while(x%i==0) x/=i;
        }
        if(x!=1) primeFactorization.push_back(x);
        return primeFactorization;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool vis[n];
        memset(vis,false,n);
        unordered_map<int,int> lastSeen; // The last index for which that prime factor was seen
        // Creating a graph between indices
        vector<int> g[n];
        for(int i=0;i<n;i++) {
            if(nums[i]==1) return false; // nums[i] is an unreachable node because hcf(1,anything) = 1
            auto primeFactors=primeFactorization(nums[i]);
            for(int pfactor:primeFactors) {
                if(lastSeen.find(pfactor)!=lastSeen.end()) {
                    g[i].push_back(lastSeen[pfactor]);
                    g[lastSeen[pfactor]].push_back(i);
                }
                else lastSeen[pfactor]=i;
            }
        }
        // Checking if the graph is connected
        dfs(0,vis,g);
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};
class Solution {
private:
    void dist(int root, int parent, vector<int> adjList[], auto& ans, auto& cnt) {
        for(int node:adjList[root]) {
            if(node==parent) continue;
            dist(node,root,adjList,ans,cnt);
            cnt[root]+=cnt[node];
            ans[root]+=ans[node]+cnt[node];
        }
        cnt[root]++;
    }
    void calc(int root, int parent, vector<int> adjList[], int n, auto& ans, auto& cnt) {
        for(int node:adjList[root]) {
            if(node==parent) continue;
            // At node, cnt[node] nodes will get one step closer and n - cnt[node] nodes will move one step away
            ans[node]=ans[root]-cnt[node]+n-cnt[node];
            calc(node,root,adjList,n,ans,cnt);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        for(auto edge:edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n,0),cnt(n,0);
        dist(0,-1,adjList,ans,cnt);
        calc(0,-1,adjList,n,ans,cnt);
        return ans;
    }
};
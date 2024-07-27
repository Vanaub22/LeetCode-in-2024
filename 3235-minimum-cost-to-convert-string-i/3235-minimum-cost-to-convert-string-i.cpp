#define INF (int)1e7
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Creating an adjacency matrix for alphabets
        vector<vector<int>> memo(26,vector<int>(26,INF));
        int m=original.size(),n=source.size();
        for(int i=0;i<m;i++) {
            int src=original[i]-'a',dst=changed[i]-'a';
            memo[src][dst]=min(memo[src][dst],cost[i]);
        }
        for(int i=0;i<26;i++) memo[i][i]=0;
        // Using Floyd-Warshall's Algorithm to precompute shortest paths between all pairs of alphabets
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    if(memo[i][k]!=INF && memo[k][j]!=INF)
                    memo[i][j]=min(memo[i][j],memo[i][k]+memo[k][j]);
                }
            }
        }
        // Computing minimum cost
        long long ans=0;
        for(int i=0;i<n;i++) {
            int src=source[i]-'a',dst=target[i]-'a';
            if(memo[source[i]-'a'][target[i]-'a']==INF) return -1; // Unreachable
            else ans+=memo[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
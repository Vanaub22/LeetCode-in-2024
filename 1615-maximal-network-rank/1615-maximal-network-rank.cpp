// Optimized T.C. from O(N^3) to O(N^2) at the cost of O(N^2) space
// O(N^3) solution passes all test cases
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> directConnection(n,vector<bool>(n,false));
        int degree[n],maxNR=-1;
        bzero(degree,sizeof(degree));
        for(auto& road:roads) {
            directConnection[road[0]][road[1]]=directConnection[road[1]][road[0]]=true;
            degree[road[0]]++,degree[road[1]]++;
        }
        for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) maxNR=max(maxNR,degree[i]+degree[j]-directConnection[i][j]);
        return maxNR;
    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int indegree[n],champion,cnt=0;
        bzero(indegree,sizeof(indegree));
        for(auto& edge:edges) indegree[edge[1]]++;
        for(int i=0;i<n;i++) if(!indegree[i]) champion=i,cnt++;
        return cnt==1?champion:-1;
    }
};
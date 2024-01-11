class Solution {
public:
    // Converting to directed graph and then DFS 
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> subordinates;
        for(int i=0;i<n;i++) if(manager[i]!=-1) subordinates[manager[i]].push_back(i);
        int maxTime=0;
        dfs_maxtime(headID,0,subordinates,informTime,maxTime);
        return maxTime;
    }
    // Performing DFS to find out the maximum time to get to subordinates
    void dfs_maxtime(int manager, int time, unordered_map<int,vector<int>>& subordinates, vector<int>& iTime, int& maxTime) {
        maxTime=max(maxTime,time);
        time+=iTime[manager];
        for(int sub:subordinates[manager]) dfs_maxtime(sub,time,subordinates,iTime,maxTime);
    }
};
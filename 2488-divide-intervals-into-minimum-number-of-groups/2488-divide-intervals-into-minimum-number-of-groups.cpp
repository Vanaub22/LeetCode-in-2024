class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> intervalPrefixSum;
        for(auto& interval:intervals) {
            intervalPrefixSum.emplace_back(interval[0],1);
            intervalPrefixSum.emplace_back(interval[1]+1,-1);
        }
        sort(intervalPrefixSum.begin(),intervalPrefixSum.end());
        int n=intervalPrefixSum.size(),ans=0,activeIntervals=0;
        for(int i=0;i<n;i++) {
            activeIntervals+=intervalPrefixSum[i].second;
            ans=max(ans,activeIntervals);
        }
        return ans;
    }
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size(),maxLeft=values[0],ans=0;
        for(int i=1;i<n;i++) {
            int currRight=values[i]-i,currLeft=values[i]+i;
            ans=max(ans,maxLeft+currRight),maxLeft=max(maxLeft,currLeft);
        }
        return ans;
    }
};
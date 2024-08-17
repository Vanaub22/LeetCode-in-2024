class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(),n=points[0].size();
        long long curr;
        vector<long long> maxPts(n),right(n);
        for(auto row:points) {
            curr=0;
            for(int j=n-1;j>=0;j--) {
                curr=max(curr,maxPts[j]);
                right[j]=curr--;
            }
            curr=0;
            for(int j=0;j<n;j++) {
                curr=max(curr,maxPts[j]);
                maxPts[j]=max(curr--,right[j])+row[j];
            }
        }
        return *max_element(maxPts.begin(),maxPts.end());
    }
};
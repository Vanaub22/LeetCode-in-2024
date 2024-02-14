class Solution {
private:
    bool covering(auto& i1, auto& i2) {
        if(i1[0]<0 || i2[0]<0 || i1[1]<0 || i2[1]<0) return false;
        if(i1[0]<=i2[0] && i1[1]>=i2[1]) {
            i2[0]=-1,i2[1]=-1; // Marking as considered/visited
            return true;
        }
        return false;
    }
public:
    // Brute Force Approach
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),remaining=n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                else if(covering(intervals[i],intervals[j])) remaining--;
            }
        }
        return remaining;
    }
};
class Solution {
public:
    // Binary Search on range of valid answers
    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(),positions.end());
        int n=positions.size(),low=0,high=positions[n-1],minForce=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(validDistribution(positions,n,mid,m)) {
                minForce=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return minForce;
    }
    // Helper function to determine if the current gap in positions can lead to a valid arrangement
    bool validDistribution(vector<int> positions, int n, int gap, int balls) {
        int prevPos=positions[0];
        balls--; // One ball is placed in positions[0]
        for(int i=0;i<n;i++) {
            if(positions[i]-prevPos>=gap) {
                balls--;
                prevPos=positions[i];
            }
            if(balls==0) return true; // All balls have been placed => Valid arrangement
        }
        return false;
    }
};
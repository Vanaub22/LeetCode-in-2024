// Using my solution to 560. Subarray Sum Equals K as a helper fn. here 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<int> pref;
        for(int i=0;i<m;i++) {
            // Converting submatrix to prefix-summed 1-D array
            pref=vector<int>(n,0);
            for(int j=i;j<m;j++) {
                for(int k=0;k<n;k++) pref[k]+=matrix[j][k];
                ans+=subarraySum(pref,target);
            }
        }
        return ans;
    }
    // Helper function to find the number of subarrays whose sum equals target
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> prefSum;
        long long prefixSum=0;
        int subarrays=0;
        for(int i:nums) {
            prefixSum+=i;
            if(prefixSum==k) subarrays++;
            if(prefSum.find(prefixSum-k)!=prefSum.end()) subarrays+=prefSum[prefixSum-k];
            prefSum[prefixSum]++;
        }
        return subarrays;
    }
};
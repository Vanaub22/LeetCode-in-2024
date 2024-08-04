#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int res=0;
        vector<int> subArraySums;
        for(int i=0;i<n;i++) {
            int subArraySum=0;
            for(int j=i;j<n;j++) {
                subArraySum=(subArraySum+nums[j])%MOD;
                subArraySums.push_back(subArraySum);
            }
        }
        sort(subArraySums.begin(),subArraySums.end());
        for(int i=left-1;i<right;i++) res=(res+subArraySums[i])%MOD;
        return res;
    }
};
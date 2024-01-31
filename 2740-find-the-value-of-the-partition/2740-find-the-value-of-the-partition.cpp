class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=INT_MAX;
        for(int i=0;i<n-1;i++) ans=min(ans,nums[i+1]-nums[i]);
        return ans;
    }
};
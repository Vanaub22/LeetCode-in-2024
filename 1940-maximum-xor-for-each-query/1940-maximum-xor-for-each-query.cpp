class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int k=pow(2,maximumBit)-1,n=nums.size(),x=0;
        for(int i:nums) x^=i;
        for(int i=n-1;i>=0;i--) ans.emplace_back(k^x), x^=nums[i];
        return ans;
    }
};
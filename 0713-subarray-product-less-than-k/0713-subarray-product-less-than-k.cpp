class Solution {
public:
    // Sliding Window Approach
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            int j=i,w_prod=1;
            while(j<nums.size()) {
                w_prod*=nums[j++];
                if(w_prod<k) ans++;
                else break;
            }
        }
        return ans;
    }
};
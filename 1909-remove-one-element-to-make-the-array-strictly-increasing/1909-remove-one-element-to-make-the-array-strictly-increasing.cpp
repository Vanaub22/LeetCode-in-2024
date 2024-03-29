class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        bool fault=false;
        for(int i=1;i<n;i++) {
            if(nums[i]<=nums[i-1]) {
                if(fault) return false;
                fault=true;
                if(i>1 && nums[i]<=nums[i-2]) nums[i]=nums[i-1];
            }
        }
        return true;
    }
};
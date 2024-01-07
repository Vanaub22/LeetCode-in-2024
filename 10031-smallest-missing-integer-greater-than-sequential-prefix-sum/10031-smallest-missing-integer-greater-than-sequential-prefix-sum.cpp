class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(),seq_sum=nums[0];
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]+1) seq_sum+=nums[i];
            else break;
        }
        sort(nums.begin(),nums.end());
        for(int i:nums)  if(i>=seq_sum) {
            if(i>seq_sum) return seq_sum;
            else seq_sum++;
        }
        return seq_sum;
    }
};
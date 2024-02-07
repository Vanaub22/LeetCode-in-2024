class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++) if(nums[i]!=1) dfs(nums,i,0,ans);
        return ans;
    }
    void dfs(vector<int>& nums, int k, int curr, int& ans) {
        if(nums[k]>=0) {
            int nesting_idx=nums[k];
            nums[k]=-1; // Marking as visited
            dfs(nums,nesting_idx,curr+1,ans);
        }
        else {
            ans=max(ans,curr);
            return;
        }
    }
};
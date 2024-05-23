class Solution {
private:
    int solve(int i, auto& nums, int k, int f[]) {
        if(i==nums.size()) return 1;
        int pick=0,notpick;
        if(nums[i]-k<0 || !f[nums[i]-k]) {
            f[nums[i]]++;
            pick=solve(i+1,nums,k,f);
            f[nums[i]]--; // Backtracking
        }
        notpick=solve(i+1,nums,k,f);
        return pick+notpick;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int f[1001]={0};
        return solve(0,nums,k,f)-1; 
    }
};
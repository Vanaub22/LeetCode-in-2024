class Solution {
private:
    void f(int i, int curr, auto& nums, int n, int& ans) {
        if(i==n) {
            ans+=curr;
            return;
        }
        f(i+1,curr^nums[i],nums,n,ans);
        f(i+1,curr,nums,n,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0,n=nums.size();
        f(0,0,nums,n,ans);
        return ans;
    }
};